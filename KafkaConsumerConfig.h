#ifndef KAFKA_CONSUMER_CONFIG_H
#define KAFKA_CONSUMER_CONFIG_H

#include <string>

class ConsumerConfig {
public:
    // Constructor
    ConsumerConfig();

    // Destructor
    ~ConsumerConfig();

    // Getters and Setters
    std::string getBootstrapServers() const;
    void setBootstrapServers(const std::string& value);

    std::string getGroupId() const;
    void setGroupId(const std::string& value);

    std::string getAutoOffsetReset() const;
    void setAutoOffsetReset(const std::string& value);

private:
    std::string bootstrap_servers;
    std::string group_id;
    std::string auto_offset_reset;
};

#endif // KAFKA_CONSUMER_CONFIG_H
