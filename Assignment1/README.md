## Producer-Consumer Explanation

The producer generates items and puts items onto the table. The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer. Mutual exclusion should be considered. We use threads in the producer program and consumer program. Shared memory is used for the “table”.

## Documentation

For this assignment I chose the maximum number of items allowed to be produced before consumption is 2. This is shown by producing until variable itemCount reaches 2 which signifies that there is the maximum number of items stored. This tells the consumer that they are able to consume as either element 0 or 1 of the shared memory buffer is full. This will iterate a total of 10 times before ending the program.

Some issues that I overcame in this assignment were the use of memory sharing. This was especially difficult at first when using shm_open(). I also had troubles with using sem_wait(), I kept allowing for the consumer and producer to call this function when the buffer was full. This then would cause an immediate consumption as the producer had produced. This was easily fixed by changing the while loop to busy wait as I hadn't previously when the buffer was full.

## Usage
How to use the Producer Consumer program

Compile code as shown below
```
gcc producer.c -pthread -lrt -o producer
gcc consumer.c -pthread -lrt -o consumer
```
Then run code as shown below
```
./producer & ./consumer &
```

## Example

The producer and consumer will iterate 10 times in this case. Once the 10th occurrence takes place you will CTRL + C to stop the processes.
This is the output from running the program:
```
[1] 747038
[2] 747039
produced 97
produced 75
consumed 97
consumed 75     #1st
produced 35
produced 12
consumed 35
consumed 12     #2nd
produced 34
produced 15
consumed 34
consumed 15     #3rd
produced 47
produced 34
consumed 47
consumed 34     #4th
produced 85
produced 64
consumed 85
consumed 64     #5th
produced 97
produced 40
consumed 97
consumed 40     #6th
produced 38
produced 83
consumed 38
consumed 83     #7th
produced 26
produced 18
consumed 26
consumed 18     #8th
produced 23
produced 99
consumed 23
consumed 99     #9th
produced 19
produced 75
consumed 19
consumed 75     #10th
^C
[1]-  Done                    ./producer
[2]+  Done                    ./consumer
```