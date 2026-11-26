#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
static void show(mode_t m,mode_t r,mode_t w,mode_t x){putchar(m&r?'r':'-');putchar(m&w?'w':'-');putchar(m&x?'x':'-');}
int main(int argc,char *argv[]){
 const char *path=argc>1?argv[1]:"permission_demo.txt";struct stat st;
 if(stat(path,&st)!=0){perror("stat");return 1;}
 struct passwd *pw=getpwuid(st.st_uid);struct group *gr=getgrgid(st.st_gid);
 printf("File: %s\nOwner: %s\nGroup: %s\n",path,pw?pw->pw_name:"unknown",gr?gr->gr_name:"unknown");
 printf("Permissions: ");show(st.st_mode,S_IRUSR,S_IWUSR,S_IXUSR);putchar(' ');
 show(st.st_mode,S_IRGRP,S_IWGRP,S_IXGRP);putchar(' ');
 show(st.st_mode,S_IROTH,S_IWOTH,S_IXOTH);putchar('\n');
 printf("Octal mode: %04o\n",st.st_mode&0777);
 puts("\nUser types: owner (u), group (g), others (o)");
 puts("Access rights: read (r=4), write (w=2), execute (x=1)");
 puts("Example command: chmod 640 permission_demo.txt");return 0;
}