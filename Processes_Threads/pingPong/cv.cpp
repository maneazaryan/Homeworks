#include <iostream>	
#include <pthread.h>

bool pingPrinted = false;
pthread_mutex_t mutex;
pthread_cond_t cond;
int n = 0;
void* ping(void* args)
{
		while(true)
		{
				pthread_mutex_lock(&mutex);

				if(n > 10)
				{
					std::cout << "Ping" << std::endl;
					pthread_cond_signal(&cond);
					pthread_mutex_unlock(&mutex);
					break;
				}
				while(pingPrinted)
				{
						pthread_cond_wait(&cond, &mutex);
				}
				std::cout << "Ping" << std::endl;

				pingPrinted = true;
				pthread_cond_signal(&cond);

				pthread_mutex_unlock(&mutex);
		}
		return NULL;
}

void* pong(void* args)
{
		while(true)
		{
				pthread_mutex_lock(&mutex);
				if(n > 10)
				{
					std::cout << "Pong" << std::endl;
					pthread_mutex_unlock(&mutex);
					break;
				}
				while(!pingPrinted)
				{
						pthread_cond_wait(&cond, &mutex);
				}
				std::cout << "Pong" << std::endl;
				n++;
				pingPrinted = false;
				pthread_cond_signal(&cond);

				pthread_mutex_unlock(&mutex);
		}
		return NULL;
}
int main()
{
		pthread_mutex_init(&mutex, NULL);
		pthread_cond_init(&cond, NULL);
		pthread_t t1, t2;

		pthread_create(&t1, NULL, ping, NULL);
		pthread_create(&t2, NULL, pong, NULL);

		pthread_join(t1, NULL);
		pthread_join(t2, NULL);
		pthread_mutex_destroy(&mutex);
		pthread_cond_destroy(&cond);
		return 0;
}	
