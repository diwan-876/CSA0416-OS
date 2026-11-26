#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]) {
    if(argc!=3){fprintf(stderr,"Usage: %s search_word filename\n",argv[0]);return 1;}
    FILE *fp=fopen(argv[2],"r"); if(!fp){perror("fopen");return 1;}
    char line[1024]; int n=0,found=0;
    while(fgets(line,sizeof line,fp)){n++;if(strstr(line,argv[1])){printf("%d:%s",n,line);found=1;}}
    fclose(fp); if(!found)puts("No matching lines found."); return 0;
}