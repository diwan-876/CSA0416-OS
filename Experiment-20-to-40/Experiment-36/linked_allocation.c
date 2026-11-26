#include <stdio.h>
#define MAX 50
int main(void){
 int n,b[MAX],i,j;
 printf("Enter number of file blocks: ");if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;
 printf("Enter block numbers in linked order: ");
 for(i=0;i<n;i++){if(scanf("%d",&b[i])!=1||b[i]<0)return 1;for(j=0;j<i;j++)if(b[j]==b[i]){puts("Duplicate block.");return 1;}}
 printf("\nLinked File Allocation\nStart block: %d\nEnd block: %d\n",b[0],b[n-1]);
 puts("Block    Next pointer");
 for(i=0;i<n;i++)printf("%-8d %d\n",b[i],i==n-1?-1:b[i+1]);
 printf("Chain: ");for(i=0;i<n;i++)printf("%d -> ",b[i]);puts("NULL");
 return 0;
}