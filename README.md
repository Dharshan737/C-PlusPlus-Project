# Simple Kafka Producer

This repository contains a simple Kafka producer program written in C++. The program uses the `librdkafka` library to produce messages to a Kafka topic. Additionally, it includes a metadata fetcher to retrieve and display Kafka metadata.

## Prerequisites

- **librdkafka**: Make sure you have `librdkafka` installed on your system. You can download and install it from [librdkafka's GitHub repository](https://github.com/edenhill/librdkafka).

## Files

- `SimpleKafkaProducer.cpp`: Contains the main implementation of the Kafka producer.
- `SimpleKafkaProducer.h`: Header file for the Kafka producer.
- `KafkaProducerConfig.cpp`: Contains the implementation of the Kafka producer configuration.
- `KafkaProducerConfig.h`: Header file for the Kafka producer configuration.
- `KafkaMetadataFetcher.cpp`: Contains the implementation for fetching and displaying Kafka metadata.
- `KafkaMetadataFetcher.h`: Header file for the Kafka metadata fetcher.

## Compilation and Execution

### Compilation

To compile the provided `SimpleKafkaProducer.cpp` file along with the configuration file, use the following command:

```sh
g++ -o SimpleKafkaProducer SimpleKafkaProducer.cpp KafkaProducerConfig.cpp -lrdkafka++
```

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

#### Kafka Metadata Fetcher

```sh
./KafkaMetadataFetcher "localhost:9092"
```

This will fetch and display the metadata of all topics (excluding the `__consumer_offsets` topic) on the Kafka broker running on `localhost:9092`.
