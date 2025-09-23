#include <iostream>	
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
bool booked = false;

void* getReadyForVacation(void* args)
{
	int i = *(int*)args;

	pthread_mutex_lock(&mutex);
	std::cout<< i << " friend checking " <<std::endl;
	while(!booked)
	{
		pthread_cond_wait(&cond, &mutex);
	}

	std::cout << i << " is happy"<< std::endl;
	pthread_mutex_unlock(&mutex);

	delete (int*)args;
	return NULL;
}
void* bookTickets(void* args)
{
	sleep(1);
	pthread_mutex_lock(&mutex);
	std::cout << "Tickets are booked" << std::endl;
	booked = true;
	pthread_cond_broadcast(&cond);
	pthread_mutex_unlock(&mutex);
	return NULL;
}
int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	pthread_t friends[5];
	pthread_t booking;

	for(int i = 1 ; i <= 5; i++)
	{
		int* num = new int(i); 
		pthread_create(&friends[i-1], NULL, getReadyForVacation, num);
	}
	pthread_create(&booking, NULL, bookTickets, NULL);

	
	for(int i = 0 ; i < 5; i++)
		pthread_join(friends[i], NULL);
	pthread_join(booking, NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}	
