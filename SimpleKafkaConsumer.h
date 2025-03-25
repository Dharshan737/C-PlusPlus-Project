#ifndef SIMPLE_KAFKA_CONSUMER_H
#define SIMPLE_KAFKA_CONSUMER_H

#include <string>
#include <librdkafka/rdkafkacpp.h>
#include "KafkaConsumerConfig.h"

// Consumes messages from a Kafka topic.
void consumeMessages(const ConsumerConfig& config, const std::string& topic);

#endif // SIMPLE_KAFKA_CONSUMER_H
