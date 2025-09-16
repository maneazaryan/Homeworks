#include <iostream>	
#include <pthread.h>

struct Args
{
	int x, y;
	Args(int a , int b) : x(a), y(b){}
};
int factorial(int n )
{
	if(n < 1 ) return 1;
	return n* factorial(n-1);
}

void* numerator(void* args)
{
	int n = *((int*)args);
	int* result = new int(factorial(n)); 
	std::cout<<"numerator : " << *result << std::endl;

	pthread_exit(result);
}

void* denominator(void* args)
{
	Args* nums = (Args*) args;
	int n = nums->x - nums->y;

	int* result = new int(factorial(n)); 
	std::cout<<"denumerator "<< *result << std::endl;
	pthread_exit(result);
}

int main()
{
	std::cout<<"Enter 2 numbers"<<std::endl;
	int P , n , s;
	std::cin>> n >> s;

	pthread_t t1;
	pthread_t t2;

	Args* args = new Args(n, s);

	pthread_create(&t1, NULL, numerator , &n);
	pthread_create(&t2, NULL, denominator , args);

	void* ret1;
	void* ret2;
	pthread_join(t1, &ret1);
	pthread_join(t2, &ret2);

	P = *((int*)ret1) / *((int*)ret2);
	std::cout <<"Result is : " << P << std::endl;


	delete args;
	delete (int*)ret1;
	delete (int*)ret2;
	return 0;
}	
