#include <stdio.h>
int main(void) {
    int nb,np,b[50],p[50],a[50];
    printf("Enter number of blocks: "); scanf("%d",&nb);
    printf("Enter block sizes: "); for(int i=0;i<nb;i++) scanf("%d",&b[i]);
    printf("Enter number of processes: "); scanf("%d",&np);
    printf("Enter process sizes: "); for(int i=0;i<np;i++) scanf("%d",&p[i]),a[i]=-1;
    for(int i=0;i<np;i++)for(int j=0;j<nb;j++)if(b[j]>=p[i]){a[i]=j;b[j]-=p[i];break;}
    puts("\nProcess\tSize\tBlock");
    for(int i=0;i<np;i++)if(a[i]>=0)printf("P%d\t%d\tB%d\n",i+1,p[i],a[i]+1);else printf("P%d\t%d\tNot allocated\n",i+1,p[i]);
    return 0;
}