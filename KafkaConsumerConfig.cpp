#include "KafkaConsumerConfig.h"

// Constructor
ConsumerConfig::ConsumerConfig()
    : bootstrap_servers("localhost:9092"), group_id("default_group"), auto_offset_reset("earliest") {}

// Destructor
ConsumerConfig::~ConsumerConfig() {}

// Getters and Setters
std::string ConsumerConfig::getBootstrapServers() const {
    return bootstrap_servers;
}

void ConsumerConfig::setBootstrapServers(const std::string& value) {
    bootstrap_servers = value;
}

std::string ConsumerConfig::getGroupId() const {
    return group_id;
}

void ConsumerConfig::setGroupId(const std::string& value) {
    group_id = value;
}

std::string ConsumerConfig::getAutoOffsetReset() const {
    return auto_offset_reset;
}

void ConsumerConfig::setAutoOffsetReset(const std::string& value) {
    auto_offset_reset = value;
}
