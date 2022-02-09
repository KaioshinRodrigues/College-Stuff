#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

char * shm_create(char *sm_name, int sm_size, int sm_flags, mode_t sm_mode, int mmap_protection){
    int fd = shm_open(sm_name, sm_flags, sm_mode);

    if (fd > 0)
    {
        ftruncate(fd, sm_size);
        return (char *)  mmap(0, sm_size, mmap_protection, MAP_SHARED, fd, 0);
    }
    
}

char * sm_WriteString(char *sm_address, char *message){
    sprintf(sm_address, "%s", message);
    return sm_address + strlen(message);
}

int main(void){
    const int SIZE = 4096;

    char *sm_address = sm_create("OS", SIZE, O_CREAT | O_RDWR, 0666, PROT_READ | PROT_WRITE);
    char *address = sm_address;

    address = sm_WriteString(address,"Hello");
    address = sm_WriteString(address,"World!\n");
    
    return 0;
}










