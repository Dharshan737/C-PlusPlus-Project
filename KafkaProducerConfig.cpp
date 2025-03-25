#include "KafkaProducerConfig.h"
#include <iostream>

/**
 * Constructor
 */
ProducerConfig::ProducerConfig()
    : client_id("default_client"),
      bootstrap_servers("localhost:9092"),
      compression_codec("none"),
      compression_level(0),
      batch_size(16384),
      queue_buffering_max_kbytes(1048576),
      linger_ms(1),
      acks(1),
      connections_max_idle_ms(540000),
      security_protocol("plaintext"),
      socket_connection_setup_timeout_ms(30000) 
{
    std::cout << "ProducerConfig constructed" << std::endl;
}

/**
 * Destructor
 */
ProducerConfig::~ProducerConfig() {
    std::cout << "ProducerConfig destroyed" << std::endl;
}

std::string ProducerConfig::getClientId() const {
    return client_id;
}

void ProducerConfig::setClientId(const std::string& value) {
    client_id = value;
}

std::string ProducerConfig::getBootstrapServers() const {
    return bootstrap_servers;
}

void ProducerConfig::setBootstrapServers(const std::string& value) {
    bootstrap_servers = value;
}

std::string ProducerConfig::getCompressionCodec() const {
    return compression_codec;
}

void ProducerConfig::setCompressionCodec(const std::string& value) {
    compression_codec = value;
}

int ProducerConfig::getCompressionLevel() const {
    return compression_level;
}

void ProducerConfig::setCompressionLevel(int value) {
    compression_level = value;
}

int ProducerConfig::getBatchSize() const {
    return batch_size;
}

void ProducerConfig::setBatchSize(int value) {
    batch_size = value;
}

int ProducerConfig::getQueueBufferingMaxKbytes() const {
    return queue_buffering_max_kbytes;
}

void ProducerConfig::setQueueBufferingMaxKbytes(int value) {
    queue_buffering_max_kbytes = value;
}

int ProducerConfig::getLingerMs() const {
    return linger_ms;
}

void ProducerConfig::setLingerMs(int value) {
    linger_ms = value;
}

int ProducerConfig::getAcks() const {
    return acks;
}

void ProducerConfig::setAcks(int value) {
    acks = value;
}

int ProducerConfig::getConnectionsMaxIdleMs() const {
    return connections_max_idle_ms;
}

void ProducerConfig::setConnectionsMaxIdleMs(int value) {
    connections_max_idle_ms = value;
}

std::string ProducerConfig::getSecurityProtocol() const {
    return security_protocol;
}

void ProducerConfig::setSecurityProtocol(const std::string& value) {
    security_protocol = value;
}

int ProducerConfig::getSocketConnectionSetupTimeoutMs() const {
    return socket_connection_setup_timeout_ms;
}

void ProducerConfig::setSocketConnectionSetupTimeoutMs(int value) {
    socket_connection_setup_timeout_ms = value;
}
