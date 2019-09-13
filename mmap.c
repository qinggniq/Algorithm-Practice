#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please add the file parameter!\n");
        return 1;
    }
    int fd = open(argv[1],O_RDWR|O_APPEND);
    
    unsigned long filesize = -1;	
	struct stat statbuff;
	if(fstat(fd, &statbuff) >= 0){
		filesize = statbuff.st_size;
	}

    char* content = (char*)mmap(NULL, filesize+10, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%s", content);
    close(fd);
    munmap(content, filesize);
    return 0;
}