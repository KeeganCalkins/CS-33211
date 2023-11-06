// Consumer Code
// Keegan Calkins

#include "table.h"

int main(int argc, char *argv[]) {
    struct table *consumer;

    int fd = shm_open("/Shared_mem", O_CREAT | O_RDWR, 0600);

    ftruncate(fd, sizeof(struct table)); // will resize shared memory to struct
    
   
    consumer = mmap(0, sizeof(struct table), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);               
                                                                    //point to shared memory
                                 
    int itemCount = 0;
    while (itemCount < MAX_ITEMS) {
        while(consumer->buffer[0] == 0 && consumer->buffer[1] == 0) // busy wait while empty
            sleep(1);
            sem_wait(&consumer->fillUnit);
        for (int i = 0; i < BUFFER_SIZE; ++i) { // consumes items directly
            printf("consumed %d\n", consumer->buffer[i]);
            consumer->buffer[i] = 0; // sets item to empty or 0
        }
        ++itemCount;
        sem_post(&consumer->emptyUnit); // marks buffer as full
    }
    return 0;
}