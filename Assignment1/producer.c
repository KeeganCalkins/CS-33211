// Producer Code
// Keegan Calkins

#include "table.h"

int main(int argc, char *argv[]) {
    srand(time(NULL)); 
    
    int fd = shm_open("/Shared_mem", O_CREAT | O_RDWR, 0600); // open shared memory
    
    ftruncate(fd, sizeof(struct table)); // will resize shared memory
    
    struct table *producer;
    producer = mmap(0, sizeof(struct table), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);               
                                                                    //point to shared memory

    // Initialize semaphores
    sem_init(&producer->fillUnit  , 1, 0);
    sem_init(&producer->emptyUnit , 1, BUFFER_SIZE);

    // empty shared buffer setting elements to 0
    for(int i = 0; i < BUFFER_SIZE; ++i) {
        producer->buffer[i] = 0;
    }

    int itemCount = 0;
    while (itemCount < MAX_ITEMS) {
        while(producer->buffer[0] != 0 && producer->buffer[1] != 0); // busy waits when full
        sleep(1);
        sem_wait(&producer->emptyUnit);
        int itemVal;
        for (int i = 0; i < BUFFER_SIZE; ++i) { // produces items directly
            itemVal = rand() % 100 + 1; // collects a random value(1-100) for the produced item
            producer->buffer[i] = itemVal; // sets item to random value
            printf("produced %d\n", itemVal);
        }
        ++itemCount;
        sem_post(&producer->fillUnit); // marks buffer as full
    }
    return 0;
}