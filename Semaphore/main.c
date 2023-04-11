#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
sem_t semlock;
void*Print(void*arg)
{
	static int i;
	sem_wait(&semlock);
	++i;
	printf("\nSemaphore Lock Start value[%d] FUNCTION[%s] LINE[%d]",i,__FUNCTION__,__LINE__);
	sleep(2);
	printf("\nSemaphore UnLock End value[%d] FUNCTION[%s] LINE[%d]",i,__FUNCTION__,__LINE__);
	sem_post(&semlock);
}
int main()
{
	pthread_t *thread;
	int i;
	thread = (pthread_t*)malloc(5 * sizeof(pthread_t));
	sem_init(&semlock,0,1);
	if(!thread)
	{
		printf("\nCo loi! khong the cap phat bo nho.");
		exit(0);
	}else{
		for(i=0;i<5;i++)
		{
			pthread_create(thread+i,NULL,Print,NULL);
			pthread_join(*(thread+i),NULL);	
		}
	}
	sem_destroy(&semlock);
	//char address[100];
	//strcpy(address, (char*)thread);
	//puts(address);
	printf("\nAdress:%s",(char*)thread);
	free(thread);
	printf("\nAdress:%s",(char*)thread);
	//puts(address);
	return 0;
}
