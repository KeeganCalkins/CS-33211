#ifndef TABLE_H
#define TABLE_H

#include <sys/mman.h>
#include <sys/stat.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX_ITEMS = 10;
const int BUFFER_SIZE = 2;

struct table {
    sem_t emptyUnit;
    sem_t fillUnit;
    int buffer[BUFFER_SIZE];
};

#endif