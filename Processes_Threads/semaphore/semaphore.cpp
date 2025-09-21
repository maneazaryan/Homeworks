#include <iostream>	
#include <vector>
#include <pthread.h>
#include <semaphore.h>
const int Count = 1;
std::vector<int> shared;

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
	if(shared.size() != Count)
	{
		shared.push_back(1);
	}
	print();
	sem_post(&full);
	return 0;
}
void* consumer(void* args)
{
	sem_wait(&full);
	if(!shared.empty())
	{
		shared.pop_back();
	}
	print();
	sem_post(&empty);
	return 0;
}
int main()
{
	sem_init(&full, 0 , 0);
	sem_init(&empty, 0 , 1);
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL , producer, NULL);	
	pthread_create(&t2, NULL , consumer, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	sem_destroy(&full);	
	sem_destroy(&empty);	
	return 0;
}	
