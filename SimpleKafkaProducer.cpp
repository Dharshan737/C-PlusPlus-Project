#include <iostream>
#include <fstream>
#include <librdkafka/rdkafkacpp.h>

class PostDeliveryReportCb : public RdKafka::DeliveryReportCb {
public:
    void dr_cb(RdKafka::Message& message) override {
        std::string logFilename = "producerLog.txt";
        std::ofstream logfile(logFilename, std::ios_base::app);

        if (message.err()) {
            if (logfile.is_open()) {
                logfile << "Message delivery failed: " << message.errstr() << std::endl;
            }
        } else {
            if (logfile.is_open()) {
                logfile << "Message: " << static_cast<const char*>(message.payload()) 
                        << " to Partition: " << message.partition() 
                        << " at offset " << message.offset() << std::endl;
            } else {
                std::cerr << "Failed to open log file." << std::endl;
            }
        }
        logfile.close();
    }
};

PostDeliveryReportCb ex_dr_cb;

RdKafka::Producer* createProducer(const std::string& brokers) {
    RdKafka::Conf* conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    std::string errstr;

    if (conf->set("bootstrap.servers", brokers, errstr) != RdKafka::Conf::CONF_OK) {
        std::cerr << errstr << std::endl;
        delete conf;
        return nullptr;
    }

    if (conf->set("dr_cb", &ex_dr_cb, errstr) != RdKafka::Conf::CONF_OK) {
        std::cerr << errstr << std::endl;
        delete conf;
        return nullptr;
    }

    RdKafka::Producer* producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) {
        std::cerr << "Failed to create producer: " << errstr << std::endl;
        delete conf;
        return nullptr;
    }

    delete conf;
    return producer;
}

void deleteProducer(RdKafka::Producer* producer) {
    if (producer) {
        producer->flush(10 * 1000);
        delete producer;
    }
}

void produceMessage(RdKafka::Producer* producer, const std::string& topic, const std::string& message) {
    RdKafka::ErrorCode err = producer->produce(
                    topic,
                    RdKafka::Topic::PARTITION_UA,
                    RdKafka::Producer::RK_MSG_COPY,
                    const_cast<char*>(message.c_str()), message.size(),
                    NULL, 0,
                    0,
                    NULL,
                    NULL);

    if (err != RdKafka::ERR_NO_ERROR) {
        std::cerr << "Failed to produce to topic " << topic << ": "
                  << RdKafka::err2str(err) << std::endl;

        if (err == RdKafka::ERR__QUEUE_FULL) {
            producer->poll(1000);
        }
    }

    producer->poll(0);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <brokers> <topic> <message>\n";
        exit(1);
    }

    std::string brokers = argv[1];
    std::string topic = argv[2];
    std::string message = argv[3];

    RdKafka::Producer* producer = createProducer(brokers);

    if (!producer) {
        std::cerr << "Failed to create producer. Exiting." << std::endl;
        return 1;
    }

    produceMessage(producer, topic, message);

    deleteProducer(producer);

    return 0;
}
