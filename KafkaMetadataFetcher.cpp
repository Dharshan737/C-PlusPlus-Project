#include <iostream>
#include <string>
#include <librdkafka/rdkafkacpp.h>

/**
 * Prints the replicas and ISRs of a partition.
 * 
 * @param replicas Vector containing replica IDs.
 * @param isrs Vector containing ISR (In-Sync Replicas) IDs.
 */
void printPartitionMetadata(const RdKafka::PartitionMetadata::ReplicasVector* replicas,
                            const RdKafka::PartitionMetadata::ISRSVector* isrs) {
    std::cout << "Replicas: ";
    for (const auto& replica : *replicas) {
        std::cout << replica << " ";
    }
    std::cout << ", ISRs: ";
    for (const auto& isr : *isrs) {
        std::cout << isr << " ";
    }
    std::cout << std::endl;
}

/**
 * Prints the metadata of all topics, excluding the "__consumer_offsets" topic.
 * 
 * @param topics Vector containing topic metadata.
 */
void printTopicMetadata(const RdKafka::Metadata::TopicMetadataVector* topics) {
    std::cout << "All Topics: " << std::endl;
    for (const auto& topicMetadata : *topics) {
        // Skip the "__consumer_offsets" topic since it is handled internally by Kafka.
        if (topicMetadata->topic() == "__consumer_offsets") {
            continue;
        }

        std::cout << "Topic: " << topicMetadata->topic() << ", Error: " << topicMetadata->err()
                  << ", PartitionCount: " << topicMetadata->partitions()->size() << std::endl;
        std::cout << "Partitions: " << std::endl;
        const RdKafka::TopicMetadata::PartitionMetadataVector* partitions = topicMetadata->partitions();
        for (const auto& partitionInfo : *partitions) {
            std::cout << "Partition Id: " << partitionInfo->id() << ", Error: " << partitionInfo->err()
                      << ", Leader: " << partitionInfo->leader() << ", ReplicationFactor: " << partitionInfo->replicas()->size() << std::endl;
            printPartitionMetadata(partitionInfo->replicas(), partitionInfo->isrs());
        }
        std::cout << std::endl;
    }
}

/**
 * Main function to fetch and print metadata from a Kafka broker.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 * @return int Exit status.
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <brokers>\n";
        exit(1);
    }

    // Get the broker addresses from the command-line argument
    std::string brokers = argv[1];

    // Create Kafka configuration object
    RdKafka::Conf* conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    std::string errstr;

    // Set the bootstrap servers
    if (conf->set("bootstrap.servers", brokers, errstr) != RdKafka::Conf::CONF_OK) {
        std::cerr << errstr << std::endl;
        delete conf;
        return 1;
    }

    // Create Kafka producer
    RdKafka::Producer* producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) {
        std::cerr << "Failed to create producer: " << errstr << std::endl;
        delete conf;
        return 1;
    }

    // Fetch metadata
    RdKafka::Metadata* metadata = nullptr;
    RdKafka::ErrorCode err = producer->metadata(true, nullptr, &metadata, 5000);
    if (err != RdKafka::ERR_NO_ERROR) {
        std::cerr << "Failed to retrieve metadata: " << RdKafka::err2str(err) << std::endl;
        delete producer;
        delete conf;
        return 1;
    }

    // Print broker information
    const RdKafka::Metadata::BrokerMetadataVector* brokersInfo = metadata->brokers();
    std::cout << "All Brokers: " << std::endl;
    for (const auto& brokerInfo : *brokersInfo) {
        std::cout << "Broker Id: " << brokerInfo->id() << ", Host: " << brokerInfo->host() << ", Port: " << brokerInfo->port() << std::endl;
    }

    // Print information about all topics (excluding "__consumer_offsets")
    printTopicMetadata(metadata->topics());

    // Clean up
    delete producer;
    delete conf;

    return 0;
}
