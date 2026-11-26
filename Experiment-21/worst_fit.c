#include <stdio.h>
int main(void) {
    int nb, np, block[50], process[50], allocation[50];
    printf("Enter number of memory blocks: "); scanf("%d", &nb);
    printf("Enter block sizes: ");
    for (int i=0;i<nb;i++) scanf("%d",&block[i]);
    printf("Enter number of processes: "); scanf("%d",&np);
    printf("Enter process sizes: ");
    for (int i=0;i<np;i++) scanf("%d",&process[i]), allocation[i]=-1;
    for (int i=0;i<np;i++) {
        int worst=-1;
        for (int j=0;j<nb;j++)
            if (block[j]>=process[i] && (worst==-1 || block[j]>block[worst])) worst=j;
        if (worst!=-1) allocation[i]=worst, block[worst]-=process[i];
    }
    puts("\nProcess\tSize\tBlock");
    for (int i=0;i<np;i++)
        if (allocation[i]!=-1) printf("P%d\t%d\tB%d\n",i+1,process[i],allocation[i]+1);
        else printf("P%d\t%d\tNot allocated\n",i+1,process[i]);
    return 0;
}