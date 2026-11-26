#include <stdio.h>
#include <stdlib.h>
int main(void){
 int n,h,q[100],i,total=0,cur;
 printf("Enter number of disk requests: ");if(scanf("%d",&n)!=1||n<1||n>100)return 1;
 printf("Enter request queue: ");for(i=0;i<n;i++)if(scanf("%d",&q[i])!=1||q[i]<0)return 1;
 printf("Enter initial head position: ");if(scanf("%d",&h)!=1||h<0)return 1;
 cur=h;printf("\nFCFS sequence: %d",h);
 for(i=0;i<n;i++){total+=abs(cur-q[i]);cur=q[i];printf(" -> %d",cur);}
 printf("\nTotal head movement = %d cylinders\n",total);return 0;
}