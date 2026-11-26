#include <stdio.h>
int main(void){int n,f,r[100],frame[20],last[20],faults=0;
printf("Number of pages: ");scanf("%d",&n);printf("Enter page reference string: ");for(int i=0;i<n;i++)scanf("%d",&r[i]);
printf("Number of frames: ");scanf("%d",&f);if(f<1||f>20)return 1;for(int j=0;j<f;j++)frame[j]=-1,last[j]=-1;
puts("\nPage\tFrames\tStatus");
for(int i=0;i<n;i++){int pos=-1;for(int j=0;j<f;j++)if(frame[j]==r[i])pos=j;
if(pos>=0){last[pos]=i;printf("%d\t",r[i]);}else{int victim=0;for(int j=0;j<f;j++)if(frame[j]==-1){victim=j;break;}else if(last[j]<last[victim])victim=j;frame[victim]=r[i];last[victim]=i;faults++;printf("%d\t",r[i]);}
for(int j=0;j<f;j++)if(frame[j]==-1)printf("- ");else printf("%d ",frame[j]);printf("\t%s\n",pos>=0?"Hit":"Fault");}
printf("Total page faults = %d\n",faults);return 0;}
