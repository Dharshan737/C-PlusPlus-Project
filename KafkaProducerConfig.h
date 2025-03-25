#ifndef KAFKA_PRODUCER_CONFIG_H
#define KAFKA_PRODUCER_CONFIG_H

#include <string>

class ProducerConfig {
public:
    // Constructor
    ProducerConfig();

    // Destructor
    ~ProducerConfig();

    // Getters and Setters
    std::string getClientId() const;
    void setClientId(const std::string& value);

    std::string getBootstrapServers() const;
    void setBootstrapServers(const std::string& value);

    std::string getCompressionCodec() const;
    void setCompressionCodec(const std::string& value);

    int getCompressionLevel() const;
    void setCompressionLevel(int value);

    int getBatchSize() const;
    void setBatchSize(int value);

    int getQueueBufferingMaxKbytes() const;
    void setQueueBufferingMaxKbytes(int value);

    int getLingerMs() const;
    void setLingerMs(int value);

    int getAcks() const;
    void setAcks(int value);

    int getConnectionsMaxIdleMs() const;
    void setConnectionsMaxIdleMs(int value);

    std::string getSecurityProtocol() const;
    void setSecurityProtocol(const std::string& value);

    int getSocketConnectionSetupTimeoutMs() const;
    void setSocketConnectionSetupTimeoutMs(int value);

private:
    std::string client_id;
    std::string bootstrap_servers;
    std::string compression_codec;
    int compression_level;
    int batch_size;
    int queue_buffering_max_kbytes;
    int linger_ms;
    int acks;
    int connections_max_idle_ms;
    std::string security_protocol;
    int socket_connection_setup_timeout_ms;
};

#endif // KAFKA_PRODUCER_CONFIG_H
