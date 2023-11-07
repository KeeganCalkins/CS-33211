## Producer-Consumer Explanation

Topic: Producer-Consumer Problem

The producer generates items and puts items onto the table. The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer. Mutual exclusion should be considered. We use threads in the producer program and consumer program. Shared memory is used for the “table”.

## Usage

Compile and run code as shown below

```
gcc producer.c -pthread -lrt -o producer
gcc consumer.c -pthread -lrt -o consumer

./producer & ./consumer &
```

## Example

The producer and consumer will iterate 10 times in this case. Once the 10th occurrence takes place you will CTRL + C to stop the processes.

You can see that the maximum number of items I allowed to be produced before consumption is 2. This is shown by producing until variable itemCount reaches 2 which signifies that there is the maximum number of items stored. This tells the consumer that they are able to consume as either element 0 or 1 of the shared memory buffer is full.

```
[3] 341359
[4] 341360
produced 1
produced 50
consumed 1
consumed 50
produced 44
produced 13
consumed 44
consumed 13
produced 70
produced 61
consumed 70
consumed 61
produced 94
produced 81
consumed 94
consumed 81
produced 100
produced 20
consumed 100
consumed 20
produced 66
produced 94
consumed 66
consumed 94
produced 25
produced 45
consumed 25
consumed 45
produced 15
produced 29
consumed 15
consumed 29
produced 36
produced 41
consumed 36
consumed 41
produced 49
produced 42
consumed 49
consumed 42
^C
[3]-  Done                    ./producer
[4]+  Done                    ./consumer
```