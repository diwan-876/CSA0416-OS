#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
void *worker(void *arg){int id=(int)(intptr_t)arg;printf("Thread %d is running.\n",id);pthread_exit((void *)(intptr_t)(id*10));}
int main(void){pthread_t t1,t2;void *r1,*r2;
pthread_create(&t1,NULL,worker,(void *)(intptr_t)1);
pthread_create(&t2,NULL,worker,(void *)(intptr_t)2);
printf("pthread_equal(t1,t2): %s\n",pthread_equal(t1,t2)?"equal":"not equal");
pthread_join(t1,&r1);pthread_join(t2,&r2);
printf("Thread 1 returned: %ld\n",(long)(intptr_t)r1);
printf("Thread 2 returned: %ld\n",(long)(intptr_t)r2);
puts("Both threads joined successfully.");return 0;}
