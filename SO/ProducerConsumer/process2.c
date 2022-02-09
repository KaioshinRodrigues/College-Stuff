#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

char * shm_create(char *sm_name, int sm_size, int sm_flags, mode_t sm_mode, int mmap_protection){
    int fd = shm_open(sm_name, sm_flags, sm_mode); //Cria se não existir uma região de memória compartilhada

    if (fd > 0)
    {
        ftruncate(fd, sm_size);
        return (char *)  mmap(0, sm_size, mmap_protection, MAP_SHARED, fd, 0); //Mapeia o objeto de memória compartilhada
    }
    
}

int main(void){
    const int SIZE = 4096;

    char *sm_address = sm_create("OS", SIZE, O_RDONLY, 0666, PROT_READ);
    
    if(!sm_address) return -1;

    printf("%s", sm_address);
    shm_unlink("ÖS");

    return 0;
}