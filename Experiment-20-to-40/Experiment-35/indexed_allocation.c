#include <stdio.h>
#define MAX 50
int main(void) {
 int n, indexBlock, blocks[MAX], i, j;
 printf("Enter index block number: "); if(scanf("%d",&indexBlock)!=1)return 1;
 printf("Enter number of data blocks: "); if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;
 printf("Enter data block numbers: ");
 for(i=0;i<n;i++){if(scanf("%d",&blocks[i])!=1||blocks[i]<0||blocks[i]==indexBlock)return 1;for(j=0;j<i;j++)if(blocks[j]==blocks[i]){puts("Duplicate block.");return 1;}}
 printf("\nIndexed File Allocation\nIndex Block: %d\n",indexBlock);
 puts("Index entry    Data block");
 for(i=0;i<n;i++)printf("%-14d %d\n",i,blocks[i]);
 puts("File blocks are accessed through the index block."); return 0;
}