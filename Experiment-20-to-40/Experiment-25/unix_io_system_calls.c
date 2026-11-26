#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
int main(void) {
    const char *name="exp25_demo.txt"; char buf[100]={0};
    int fd=open(name,O_CREAT|O_RDWR|O_TRUNC,0644);
    if(fd<0){perror("open");return 1;}
    write(fd,"Hello UNIX system calls",23);
    lseek(fd,0,SEEK_SET); read(fd,buf,23); printf("File content: %s\n",buf);
    int flags=fcntl(fd,F_GETFL); printf("fcntl flags: %d\n",flags); close(fd);
    struct stat st; if(stat(name,&st)==0)printf("File size: %ld bytes\n",(long)st.st_size);
    DIR *d=opendir("."); if(!d){perror("opendir");return 1;}
    puts("Directory entries (first five):"); struct dirent *e; int count=0;
    while((e=readdir(d))&&count<5){printf("%s\n",e->d_name);count++;}
    closedir(d); return 0;
}