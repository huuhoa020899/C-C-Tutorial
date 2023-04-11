#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t mutex;
void *Print(void *arg)
{
	static int i;
	pthread_mutex_lock(&mutex);
	++i;
	printf("\nMutex Lock Start value[%d] FUNCTION[%s] LINE[%d]",i,__FUNCTION__,__LINE__);
	sleep(2);
	printf("\nMutex UnLocj End value[%d] FUNCTION[%s] LINE[%d]",i,__FUNCTION__,__LINE__);
	pthread_mutex_unlock(&mutex);
}
int main()
{
	pthread_t thread1,thread2;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&thread1,NULL,Print,NULL);
	pthread_create(&thread2,NULL,Print,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
