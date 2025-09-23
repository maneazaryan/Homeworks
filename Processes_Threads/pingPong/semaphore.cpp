#include <iostream>	
#include <pthread.h>
#include <semaphore.h>
int i = 10;
sem_t sem1, sem2;
void* ping(void* args)
{
	while(i > 0 )
	{
		sem_wait(&sem1);
		std::cout << "Ping" << std::endl;
		sem_post(&sem2);
	}
	return NULL;
}
void* pong(void* args)
{
	while(i > 0)
	{
		sem_wait(&sem2);
		i--;
		std::cout << "Pong" << std::endl;
		sem_post(&sem1);
	}
	return NULL;
}
int main()
{
	sem_init(&sem1, 0 ,1 );
	sem_init(&sem2, 0 ,0 );
	
	pthread_t t1, t2;
	pthread_create(&t1, NULL, ping, NULL);
	pthread_create(&t2, NULL, pong, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL); 
	
	sem_destroy(&sem1);
	sem_destroy(&sem2);
	return 0;
}	
