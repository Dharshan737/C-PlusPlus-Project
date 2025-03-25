# Simple Kafka Producer

This repository contains a simple Kafka producer program written in C++. The program uses the `librdkafka` library to produce messages to a Kafka topic.

## Prerequisites

- **librdkafka**: Make sure you have `librdkafka` installed on your system. You can download and install it from [librdkafka's GitHub repository](https://github.com/edenhill/librdkafka).

## Files

- `SimpleKafkaProducer.cpp`: Contains the main implementation of the Kafka producer.
- `SimpleKafkaProducer.h`: Header file for the Kafka producer.

## Compilation and Execution

### Compilation

To compile the provided `SimpleKafkaProducer.cpp` file, use the following command:

```sh
g++ -o SimpleKafkaProducer SimpleKafkaProducer.cpp -lrdkafka++
```

### Execution

After successful compilation, you can run the executable with the following command:

```sh
./SimpleKafkaProducer <brokers> <topic> <message>
```

Replace `<brokers>`, `<topic>`, and `<message>` with the actual broker address, topic name, and message you want to send.

### Example

```sh
./SimpleKafkaProducer "localhost:9092" "test_topic" "Hello, Kafka!"
```

This will produce the message "Hello, Kafka!" to the `test_topic` on the Kafka broker running on `localhost:9092`.
