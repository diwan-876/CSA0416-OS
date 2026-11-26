#include <stdio.h>
int main(void){int n,f,ref[100],frame[20],next=0,faults=0;
printf("Number of pages: ");scanf("%d",&n);printf("Enter page reference string: ");for(int i=0;i<n;i++)scanf("%d",&ref[i]);
printf("Number of frames: ");scanf("%d",&f);if(f<1||f>20)return 1;for(int i=0;i<f;i++)frame[i]=-1;
puts("\nPage\tFrames\tStatus");
for(int i=0;i<n;i++){int hit=0;for(int j=0;j<f;j++)if(frame[j]==ref[i])hit=1;
if(hit)printf("%d\t",ref[i]);else{frame[next]=ref[i];next=(next+1)%f;faults++;printf("%d\t",ref[i]);}
for(int j=0;j<f;j++)if(frame[j]==-1)printf("- ");else printf("%d ",frame[j]);
printf("\t%s\n",hit?"Hit":"Fault");}
printf("Total page faults = %d\n",faults);return 0;}
