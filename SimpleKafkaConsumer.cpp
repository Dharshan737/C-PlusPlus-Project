#include "SimpleKafkaConsumer.h"
#include <iostream>
#include <csignal>

// Signal handler for graceful shutdown
volatile sig_atomic_t run = 1;

void sigterm(int sig) {
    run = 0;
}

void consumeMessages(const ConsumerConfig& config, const std::string& topic) {
    std::string errstr;

    // Create consumer configuration
    RdKafka::Conf* conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    if (conf->set("bootstrap.servers", config.getBootstrapServers(), errstr) != RdKafka::Conf::CONF_OK ||
        conf->set("group.id", config.getGroupId(), errstr) != RdKafka::Conf::CONF_OK ||
        conf->set("auto.offset.reset", config.getAutoOffsetReset(), errstr) != RdKafka::Conf::CONF_OK) {
        std::cerr << "Configuration error: " << errstr << std::endl;
        delete conf;
        return;
    }

    // Create Kafka consumer
    RdKafka::KafkaConsumer* consumer = RdKafka::KafkaConsumer::create(conf, errstr);
    if (!consumer) {
        std::cerr << "Failed to create consumer: " << errstr << std::endl;
        delete conf;
        return;
    }

    // Subscribe to topic
    std::vector<std::string> topics = {topic};
    RdKafka::ErrorCode err = consumer->subscribe(topics);
    if (err) {
        std::cerr << "Failed to subscribe to " << topic << ": " << RdKafka::err2str(err) << std::endl;
        delete consumer;
        delete conf;
        return;
    }

    // Register signal handler for graceful shutdown
    signal(SIGINT, sigterm);
    signal(SIGTERM, sigterm);

    // Consume messages
    while (run) {
        RdKafka::Message* msg = consumer->consume(1000);
        switch (msg->err()) {
            case RdKafka::ERR_NO_ERROR:
                std::cout << "Received message: " << static_cast<const char*>(msg->payload()) << std::endl;
                break;
            case RdKafka::ERR__TIMED_OUT:
                break;
            default:
                std::cerr << "Consumer error: " << msg->errstr() << std::endl;
                run = 0;
                break;
        }
        delete msg;
    }

    // Clean up
    consumer->close();
    delete consumer;
    delete conf;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <topic> <group_id>\n";
        return 1;
    }

    std::string topic = argv[1];
    std::string group_id = argv[2];

    ConsumerConfig config;
    config.setGroupId(group_id);
    consumeMessages(config, topic);

    return 0;
}
