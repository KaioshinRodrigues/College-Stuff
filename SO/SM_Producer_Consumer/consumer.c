#include <stdio.h>
#include <stdlib.h>
#include "producer_consumer.h"
#include "shared_memory.h"

int main(int argc, char *argv[]){
    int out = 0;
    size_t buffer_size = BUFFER_SIZE * sizeof(int);
    int *buffer = (int *) shm_create("buffer", buffer_size, O_CREAT | O_RDWR, 0666, PROT_READ | PROT_WRITE);
    int *count = (int *) shm_create("count", sizeof(int), O_CREAT | O_RDWR, 0666, PROT_READ | PROT_WRITE);
    
        while(*count != 10){
        int item_consumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        (*count)--;

        printf("Consumed! count = %d\n", *count);
    }
}