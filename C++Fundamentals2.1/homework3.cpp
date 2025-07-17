//Write the implementation of the following function initializing array elements with random integers.

//void initArray( int* pArr );

/*#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void initArray(int*pArr)
	{
		srand(time(0));
		int size =*pArr;
		int* arr=new int[size];
		for(int i=0;i< size; i++)
		{
			arr[i]=rand()%1001;//մինչև 1000 թվերի համար
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		delete[] arr;
	}

int main()
{
	int n;
	cout<<"Enter a number"<<endl;
	cin>>n;	
	initArray(&n);
	return 0;
}
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initArray(int*pArr, int size)
        {
                srand(time(0));
                for(int i=0;i< size; i++)
                {
                        pArr[i]=rand()%1001;//մինչև 1000 թվերի համար
                        cout<<pArr[i]<<" ";
                }
                cout<<endl;
        }
int main()
{
        int n;
        cout<<"Enter a number"<<endl;
        cin>>n; 
        int* arr=new int[n];
        initArray(arr, n);
	delete[] arr;
        return 0;
}




//Write the implementation of the following function initializing matrix elements with random integers.

//void initArray( int** ppMatrix );
/*
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void initArray(int**ppMatrix, int row, int col)
{	
	srand(time(0));
	for (int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			ppMatrix[i][j]=rand()%100;
			cout<<ppMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	cout<<"enter two numbers"<<endl;
	int row,col;
	cin>>row>>col;

	int**matrix=new int*[row];
	for(int i=0; i<row; i++)
	{
		matrix[i]=new int[col];
	}
	initArray(matrix, row, col);

	for(int i=0; i<row; i++) delete[]matrix[i];	
	delete[] matrix;
	return 0;
}*/

//Implement a function determining whether the number is prime or not.
/*
#include <iostream>
using namespace std;
void  prime(int n)
{
	int count= 0;
	for(int i=1; i<=n; i++)
	{
		if(n%i==0)
		{
			count++;
			if (count>2)
			{
				cout <<"not prime"<<endl;
				break;
			}
		}
	}
	if(count ==2) cout<<"prime"<<endl;
}
int main()
{	
	int num;
	cin>>num;
	if(num<0)
	{
		cout<<"error"<<endl;
		return 1;
	}
	prime(num);
	return 0;
}*/
//swap

/*
#include <iostream>
using namespace std;

void swap(int left , int right)
{
	int num = left;
	left=right;
	right = num;
	cout << left<<" " << right<<endl;
}

int main()
{
	int a = 23, b =76;
	swap(a,b);
	return 0;
}

*/


//#include <iostream>
//using namespace std;
/*#include <ctime>
#include <cstdlib>
void  arrMaxIndex(int* arr, int n)
{
	int maxIndex=0;
	int max=arr[maxIndex];
	for(int i=1 ; i< n; i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			maxIndex=i;
		}
	}
	cout<<maxIndex<<" Max index " << endl;
}

int main()
{
	int size;
	cin>>size;
	srand(time(0));
	int* arr= new int[size];
	for(int i=0; i<size; i++)
	{
		arr[i]=rand()%101;
		cout <<arr[i] <<" ";
	}
	cout <<endl;

	arrMaxIndex(arr,size);
	return 0;

} */

/*Implement a function that will get a positive integer number as an argument and return its binary representation as a string. Use bitwise operators for your solution.
#include <string>
string binary(int n)
{
	string bin="";
	while (n>=1)
	{
		if(n%2==0) bin="0"+bin ;
		else if (n%2==1) bin ="1"+bin;
		n = n >> 1;
	}	
	cout<<bin<<endl;
	return bin;
	
}

int main()
{
	unsigned int num;
	cin>> num;
	if(num<=0) return 1;
	binary(num);
	 return 0;
}
*/
/*

#include <string>

string hex(int n)
{	
	
	string hex="";
	while (n>0)
	{
		string hnum="0123456789ABCDEF";
		int a = n%16;
		hex = hnum[a]+hex;
		n/=16;
	}
	cout<<hex<<endl;
	return hex;
}

int main()
{
        unsigned int num;
        cin>> num;
        if(num<=0) return 1;
        hex(num);
        return 0;
}
*/

