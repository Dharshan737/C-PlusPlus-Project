#ifndef RDKAFKA_PRODUCER_H 
#define RDKAFKA_PRODUCER_H

#include <iostream>
#include <fstream>
#include <string>
#include <librdkafka/rdkafkacpp.h>

/**************** Callback functions **************/
class PostDeliveryReportCb : public RdKafka::DeliveryReportCb {
public:
    void dr_cb(RdKafka::Message& message);
};

/************* Producer Creation *****************/
RdKafka::Producer* createProducer(const std::string& brokers);

/*********** Producer Deletion *****************/
void deleteProducer(RdKafka::Producer* producer);

/******************** Sending Message *****************/
void produceMessage(RdKafka::Producer* producer, const std::string& topic, const std::string& message);

#endif
