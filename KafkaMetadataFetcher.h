#ifndef KAFKA_METADATA_FETCHER_H
#define KAFKA_METADATA_FETCHER_H

#include <string>
#include <librdkafka/rdkafkacpp.h>

/**
 * Prints the replicas and ISRs of a partition.
 * 
 * @param replicas Vector containing replica IDs.
 * @param isrs Vector containing ISR (In-Sync Replicas) IDs.
 */
void printPartitionMetadata(const RdKafka::PartitionMetadata::ReplicasVector* replicas,
                            const RdKafka::PartitionMetadata::ISRSVector* isrs);

/**
 * Prints the metadata of all topics, excluding the "__consumer_offsets" topic.
 * 
 * @param topics Vector containing topic metadata.
 */
void printTopicMetadata(const RdKafka::Metadata::TopicMetadataVector* topics);

#endif // KAFKA_METADATA_FETCHER_H
