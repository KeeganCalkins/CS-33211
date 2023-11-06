#ifndef TABLE_H
#define TABLE_H

#include <sys/mman.h>
#include <sys/stat.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 2

const int MAX_ITEMS = 10;

struct table {
    int buffer[BUFFER_SIZE];
    sem_t emptyUnit;
    sem_t fillUnit;
};

#endif