// Consumer Code
// Keegan Calkins

#include "table.h"

int main(int argc, char *argv[]) {
    int             fd;
    char            *shmpath;
    struct table    *consumer;

    shmpath = argv[1];

    fd = shm_open(shmpath, O_RDWR, 0);
    if (fd == -1) {
        errExit("shm_open() error");
    }

    if(ftruncate(fd, sizeof(*consumer)) == -1) {
        errExit("ftruncate() error");
    } else {
        ftruncate(fd, sizeof(*consumer)); // will resize shared memory
    }
    
    producer = static_cast<table*>(mmap(NULL, sizeof(*consumer), PROT_READ|PROT_WRITE,
                                 MAP_SHARED, fd, 0));               //point to shared memory
    if (consumer == MAP_FAILED) {
        errExit("mmap() error");
    }

    int itemCount = 0;
    while (itemCount < MAX_ITEMS) {
        while(consumer->buffer[0] != 0 && consumer->buffer(1) != 0) { // busy wait while empty
            // sleep(1);
            sem_wait(&consumer->fillUnit);
        }
        int itemVal;
        for (int i = 0; i < BUFFER_SIZE; ++i) { // consumes items directly
            printf("consumed %d\n", consumer->buffer[i]);
            consumer->buffer[i] = 0; // sets item to empty or 0
        }
        ++itemCount;
        sem_post(&consumer->emptyUnit); // marks buffer as full
    }
    return 0;
}