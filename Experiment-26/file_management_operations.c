#include <stdio.h>
#include <stdlib.h>
int main(void) {
    FILE *fp=fopen("exp26_file.txt","w");
    if(!fp){perror("fopen");return 1;}
    fputs("Operating System File Management\n",fp); fclose(fp);
    puts("1. File created and written.");
    fp=fopen("exp26_file.txt","a"); if(!fp){perror("fopen");return 1;}
    fputs("Append operation completed.\n",fp); fclose(fp);
    puts("2. Data appended.");
    char line[120]; fp=fopen("exp26_file.txt","r"); if(!fp){perror("fopen");return 1;}
    puts("3. File contents:");
    while(fgets(line,sizeof line,fp))fputs(line,stdout);
    fclose(fp); puts("4. File closed."); return 0;
}