#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 1
int buffer, item_ready=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void *producer(void *arg){(void)arg;pthread_mutex_lock(&mutex);buffer=42;item_ready=1;printf("Producer produced: %d\n",buffer);pthread_cond_signal(&cond);pthread_mutex_unlock(&mutex);return NULL;}
void *consumer(void *arg){(void)arg;pthread_mutex_lock(&mutex);while(!item_ready)pthread_cond_wait(&cond,&mutex);printf("Consumer consumed: %d\n",buffer);item_ready=0;pthread_mutex_unlock(&mutex);return NULL;}
int main(void){pthread_t p,c;pthread_create(&c,NULL,consumer,NULL);pthread_create(&p,NULL,producer,NULL);pthread_join(p,NULL);pthread_join(c,NULL);puts("Producer-consumer synchronization completed.");return 0;}
