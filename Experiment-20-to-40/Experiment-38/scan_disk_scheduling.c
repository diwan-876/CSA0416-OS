#include <stdio.h>
#include <stdlib.h>
int main(void){
 int n,h,m,q[100],i,j,d,total=0,cur;
 printf("Enter number of requests: ");if(scanf("%d",&n)!=1||n<1||n>100)return 1;
 printf("Enter request queue: ");for(i=0;i<n;i++)if(scanf("%d",&q[i])!=1)return 1;
 printf("Enter initial head position: ");if(scanf("%d",&h)!=1)return 1;
 printf("Enter maximum cylinder number: ");if(scanf("%d",&m)!=1||m<=h)return 1;
 printf("Direction (1=up, 0=down): ");if(scanf("%d",&d)!=1)return 1;
 for(i=0;i<n;i++)for(j=i+1;j<n;j++)if(q[i]>q[j]){int t=q[i];q[i]=q[j];q[j]=t;}
 cur=h;printf("\nSCAN sequence: %d",h);
 if(d==1){for(i=0;i<n;i++)if(q[i]>=h){total+=abs(cur-q[i]);cur=q[i];printf(" -> %d",cur);}total+=m-cur;cur=m;printf(" -> %d",cur);for(i=n-1;i>=0;i--)if(q[i]<h){total+=abs(cur-q[i]);cur=q[i];printf(" -> %d",cur);}}
 else{for(i=n-1;i>=0;i--)if(q[i]<=h){total+=abs(cur-q[i]);cur=q[i];printf(" -> %d",cur);}total+=cur;cur=0;printf(" -> 0");for(i=0;i<n;i++)if(q[i]>h){total+=abs(cur-q[i]);cur=q[i];printf(" -> %d",cur);}}
 printf("\nTotal head movement = %d cylinders\n",total);return 0;
}