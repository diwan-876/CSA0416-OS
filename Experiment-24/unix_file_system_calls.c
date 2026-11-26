#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(void) {
    const char *name="exp24_demo.txt", *msg="UNIX file system calls demo\n";
    char buf[128]={0};
    int fd=open(name,O_CREAT|O_WRONLY|O_TRUNC,0644);
    if(fd<0){perror("open");return 1;}
    if(write(fd,msg,strlen(msg))<0){perror("write");close(fd);return 1;}
    close(fd); puts("File created and data written.");
    fd=open(name,O_RDONLY); if(fd<0){perror("open");return 1;}
    ssize_t n=read(fd,buf,sizeof(buf)-1); if(n<0){perror("read");close(fd);return 1;}
    close(fd); printf("Read from file: %s",buf);
    puts("File descriptor closed successfully."); return 0;
}