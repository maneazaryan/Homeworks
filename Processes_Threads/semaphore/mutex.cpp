#include <iostream>	
#include <pthread.h>

int i = 0;
pthread_mutex_t mutex ;

void* increment(void* args)
{
	pthread_mutex_lock(&mutex);
	i++;
	std::cout << i << "  after increment" << std::endl;
	pthread_mutex_unlock(&mutex);
	return 0;
}
void* decrement(void* args)
{
	pthread_mutex_lock(&mutex);
	i--;
	std::cout << i << "  after decrement" << std::endl;
	pthread_mutex_unlock(&mutex);
	return 0;
}
int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_t thread[4];
	for( int i = 0 ; i < 4 ; i++)
	{
		if(i%2 == 0)
			pthread_create(&thread[i], NULL, increment, NULL);
		else
			pthread_create(&thread[i], NULL, decrement, NULL);
	}
	for( int i = 0 ; i < 4 ; i++)
		pthread_join(thread[i], NULL);

	pthread_mutex_destroy(&mutex);	
	return 0;
}	
