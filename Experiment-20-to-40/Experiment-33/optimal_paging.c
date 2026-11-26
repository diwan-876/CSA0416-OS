#include <stdio.h>
int main(void){int n,f,r[100],frame[20],faults=0;
printf("Number of pages: ");scanf("%d",&n);printf("Enter page reference string: ");for(int i=0;i<n;i++)scanf("%d",&r[i]);
printf("Number of frames: ");scanf("%d",&f);if(f<1||f>20)return 1;for(int j=0;j<f;j++)frame[j]=-1;
puts("\nPage\tFrames\tStatus");
for(int i=0;i<n;i++){int hit=0;for(int j=0;j<f;j++)if(frame[j]==r[i])hit=1;
if(!hit){int victim=-1,far=-1;for(int j=0;j<f;j++){if(frame[j]==-1){victim=j;break;}int k;for(k=i+1;k<n;k++)if(r[k]==frame[j])break;if(k>far){far=k;victim=j;}}frame[victim]=r[i];faults++;}
printf("%d\t",r[i]);for(int j=0;j<f;j++)if(frame[j]==-1)printf("- ");else printf("%d ",frame[j]);printf("\t%s\n",hit?"Hit":"Fault");}
printf("Total page faults = %d\n",faults);return 0;}
