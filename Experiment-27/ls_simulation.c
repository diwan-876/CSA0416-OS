#include <stdio.h>
#include <dirent.h>
int main(void) {
    DIR *dir=opendir("."); if(!dir){perror("opendir");return 1;}
    struct dirent *entry; puts("Directory listing:");
    while((entry=readdir(dir))!=NULL) printf("%s\n",entry->d_name);
    closedir(dir); return 0;
}