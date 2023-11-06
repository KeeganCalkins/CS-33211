// Producer Code
// Keegan Calkins

#include "table.h"

int main(int argc, char *argv[]) {
    srand(time(NULL)); 
    int             fd;
    char            *shmpath;
    struct table    *producer;
    
    fd = shm_open(shmpath, O_CREAT | O_EXCL | O_RDWR, 0600); // open shared memory
    if (fd == -1) {
        errExit("shm_open() error");
    }

    if(ftruncate(fd, sizeof(*producer)) == -1) {
        errExit("ftruncate() error");
    } else {
        ftruncate(fd, sizeof(*producer)); // will resize shared memory
    }

    producer = static_cast<table*>(mmap(NULL, sizeof(*producer), PROT_READ|PROT_WRITE,
                                 MAP_SHARED, fd, 0));               //point to shared memory
    if (producer == MAP_FAILED) {
        errExit("mmap() error");
    }

    // Initialize semaphores
    sem_init(&(producer->fillUnit ) , 1, 0);
    sem_init(&(producer->emptyUnit) , 1, BUFFER_SIZE);

    // empty shared buffer setting elements to 0
    for(int i = 0; i < BUFFER_SIZE; ++i) {
        producer->buffer[i] = 0;
    }

    int itemCount = 0;
    while (itemCount < MAX_ITEMS) {
        while(producer->buffer[0] != 0 && producer->buffer(1) != 0) {
            // sleep(1);
            sem_wait(&producer->emptyUnit);
        }
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