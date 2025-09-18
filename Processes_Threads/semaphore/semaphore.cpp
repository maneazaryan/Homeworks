#include <iostream>	
#include <vector>
#include <pthread.h>
#include <semaphore.h>
const int Count = 1;
std::vector<int> shared;

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

void print()
{
	if(shared.empty())
		std::cout << "No data" <<std::endl;
	for(const int& a : shared)
		std::cout << a << ' ';
	std::cout << std::endl;
}

void* producer(void* args)
{
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	if(shared.size() != Count)
	{
		shared.push_back(1);
	}
	print();
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
	return 0;
}
void* consumer(void* args)
{
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	if(!shared.empty())
	{
		shared.pop_back();
	}
	print();
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	return 0;
}
int main()
{
	pthread_mutex_init(&mutex, NULL);
	sem_init(&full, 0 , 0);
	sem_init(&empty, 0 , 1);
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL , producer, NULL);	
	pthread_create(&t2, NULL , consumer, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);
	sem_destroy(&full);	
	sem_destroy(&empty);	
	return 0;
}	
