# Simple Kafka Producer and Consumer

This repository contains simple Kafka producer and consumer programs written in C++. The programs use the `librdkafka` library to produce and consume messages to/from a Kafka topic. Additionally, it includes a metadata fetcher to retrieve and display Kafka metadata.

## Prerequisites

- **librdkafka**: Make sure you have `librdkafka` installed on your system. You can download and install it from [librdkafka's GitHub repository](https://github.com/edenhill/librdkafka).

## Files

### Producer

- `SimpleKafkaProducer.cpp`: Contains the main implementation of the Kafka producer.
- `SimpleKafkaProducer.h`: Header file for the Kafka producer.
- `KafkaProducerConfig.cpp`: Contains the implementation of the Kafka producer configuration.
- `KafkaProducerConfig.h`: Header file for the Kafka producer configuration.

### Consumer

- `SimpleKafkaConsumer.cpp`: Contains the main implementation of the Kafka consumer.
- `SimpleKafkaConsumer.h`: Header file for the Kafka consumer.
- `KafkaConsumerConfig.cpp`: Contains the implementation of the Kafka consumer configuration.
- `KafkaConsumerConfig.h`: Header file for the Kafka consumer configuration.

### Metadata Fetcher

- `KafkaMetadataFetcher.cpp`: Contains the implementation for fetching and displaying Kafka metadata.
- `KafkaMetadataFetcher.h`: Header file for the Kafka metadata fetcher.

## Compilation and Execution

### Compilation

#### Kafka Producer

To compile the provided `SimpleKafkaProducer.cpp` file along with the configuration file, use the following command:

```sh
g++ -o SimpleKafkaProducer SimpleKafkaProducer.cpp KafkaProducerConfig.cpp -lrdkafka++
```

#### Kafka Consumer

To compile the provided `SimpleKafkaConsumer.cpp` file along with the configuration file, use the following command:

```sh
g++ -o SimpleKafkaConsumer SimpleKafkaConsumer.cpp KafkaConsumerConfig.cpp -lrdkafka++
```

#### Kafka Metadata Fetcher

To compile the `KafkaMetadataFetcher.cpp` file, use the following command:

```sh
g++ -o KafkaMetadataFetcher KafkaMetadataFetcher.cpp -lrdkafka++
```

### Execution

#### Kafka Producer

After successful compilation, you can run the executable with the following command:

```sh
./SimpleKafkaProducer <brokers> <topic> <message>
```

Replace `<brokers>`, `<topic>`, and `<message>` with the actual broker address, topic name, and message you want to send.

#### Kafka Consumer

After successful compilation, you can run the executable with the following command:

```sh
./SimpleKafkaConsumer <brokers> <group_id> <topic>
```

Replace `<brokers>`, `<group_id>`, and `<topic>` with the actual broker address, consumer group ID, and topic name.

#### Kafka Metadata Fetcher

After successful compilation, you can run the executable with the following command:

```sh
./KafkaMetadataFetcher <brokers>
```

Replace `<brokers>` with the actual broker address.

### Examples

#### Kafka Producer

```sh
./SimpleKafkaProducer "localhost:9092" "test_topic" "Hello, Kafka!"
```

This will produce the message "Hello, Kafka!" to the `test_topic` on the Kafka broker running on `localhost:9092`.

#### Kafka Consumer

```sh
./SimpleKafkaConsumer "localhost:9092" "test_group" "test_topic"
```

This will consume messages from the `test_topic` on the Kafka broker running on `localhost:9092` using the consumer group `test_group`.

#### Kafka Metadata Fetcher

```sh
./KafkaMetadataFetcher "localhost:9092"
```

This will fetch and display the metadata of all topics (excluding the `__consumer_offsets` topic) on the Kafka broker running on `localhost:9092`.
