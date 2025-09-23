#include <iostream>	
#include <pthread.h>

int max = 5;
int n = 1;
bool isZero = true;
bool isEven = false;
bool isOdd = false;

pthread_mutex_t mutex;
pthread_cond_t cond;

void* zero(void* args)
{
		while(true)
		{
				pthread_mutex_lock(&mutex);
				while(!isZero )
				{
						pthread_cond_wait(&cond, &mutex);
				}
				if( n > max)
				{
						pthread_cond_broadcast(&cond);
						pthread_mutex_unlock(&mutex);
						break;
				}
				isZero = false;
				std::cout << 0 ;
				if( n% 2 == 1)
						isOdd = true;
				else
						isEven = true;
				pthread_cond_broadcast(&cond);
				pthread_mutex_unlock(&mutex);
		}
		return NULL;
}
void* odd(void* args)
{
		while(true)
		{
				pthread_mutex_lock(&mutex);
				while(!isOdd && n <= max)
				{
						pthread_cond_wait(&cond, &mutex);
				}
				if( n > max)
				{
						pthread_mutex_unlock(&mutex);
						break;
				}
				std::cout << "\033[91m" << n<< "\033[0m" ;
				n++;
				isZero = true;
				isOdd  = false;
				pthread_cond_broadcast(&cond);
				pthread_mutex_unlock(&mutex);
		}
		return NULL;
}
void* even(void* args)
{
		while(true)
		{
				pthread_mutex_lock(&mutex);
				while(!isEven && n <= max)
				{
						pthread_cond_wait(&cond, &mutex);
				}
				if( n > max)
				{
						pthread_mutex_unlock(&mutex);
						break;
				}
				std::cout << "\033[92m"<< n <<  "\033[0m";
				n++;
				isZero = true;
				isEven = false;
				pthread_cond_broadcast(&cond);
				pthread_mutex_unlock(&mutex);
		}
		return NULL;
}
int main()
{
		pthread_mutex_init(&mutex, NULL);
		pthread_cond_init(&cond,NULL);
		pthread_t t1, t2, t3;

		pthread_create(&t1, NULL, zero, NULL);
		pthread_create(&t2, NULL, odd,	NULL);
		pthread_create(&t3, NULL, even, NULL);

		pthread_join(t1, NULL);
		pthread_join(t2, NULL);
		pthread_join(t3, NULL);
		pthread_mutex_destroy(&mutex);
		pthread_cond_destroy(&cond);
		return 0;
}	
