#include <iostream>
#include <vector>
using namespace std;
/*Գրել ֆունկցիա, որը կշրջի vector-ի [index_a;index_b] միջակայքում գտնվող էլեմենտները։
Կանչել այդ ֆունկցիան intervals vector-ում տրված զույգերի համար։
Ենթադրվում է, որ intervals-ում կարող են փոխանցվել սխալ միջակայքեր։ Ուշադրություն դարձնել այդպիսի բոլոր դեպքերը բացառելուն։
Խնդրի լուծման համար օգտագործել iterator-ներ։
*/
/*int swap(vector<int>&first,int a, int b)
	{
	vector<int>::iterator it = first.begin();
	if (a>=b || a ==0 || b ==0 || a>=first.size() || b>=first.size()) return 1;

	while(a<b)
		{	
			int res=*(it+a);
			*(it+a)=*(it+b);
			*(it+b)=res;
			a++;
			b--;
		}
		return 0;
	}
int main()
{
	vector<int>v= {5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7};
	vector<int>nums=  {2, 4, 3, 7, 5, 3, 4, 6);
	for(int i=0;i<nums.size(); i+=2)
		{		
			int a=nums[i];
			int b=nums[i+1];
			swap(v,a,b);
		}
	for( int a:v)
		{ cout <<a<<" ";}
	cout<<endl;
	return 0;
}*/

/*
int swap(vector<int>&test, int a,int b)
{
	vector<int>::iterator itt= test.begin();
	for (;itt!=test.end() ; itt++)
	while(a<b)
	{int res= *(itt+a);
	*(itt+a)=*(itt+b);
	*(itt+b)=res;
	a++;
	b--;}
	return 0;
}


int main()
{	vector<int> n = {12,2,4,6,7,9,0,11,14,17};
	vector<int> num ={2,5,6,7};
	for(int i=0; i< num.size(); i+=2)
		{
			int a = num[i];
			int b = num[i+1];
			if (a>=b) return 1;
			swap(n,a,b);
		}
	for(int t:n)
		{cout <<t<<" ";}
	return 0;
}*/
/*
bool sum(vector<int>&test, int n)
{
	vector<int>::iterator it = test.begin();
	for(;it!=test.end()-3;it++)
		for(vector<int>::iterator a = (it+1);a!=test.end()-2;a++)
			for(vector<int>::iterator b =( a+1);b!=test.end()-1;b++)
				for(vector<int>::iterator  c = (b+1);c!=test.end();c++)
					if(*it+*a+*b+*c==n)
					{	cout<< *it<<"+"<<*a<<"+"<<*b<<"+"<<*c<<"="<<*it+*a+*b+*c<<endl;
						return true;
					}
	return false;
}
int main()
{
	vector<int>v={10,20,30,40,50,60,70,80,90};
	int num =40;
	sum(v,num);
	return 0;
}*/



/* magick number
int findMagicalNumber(vector<int>& arr) {
        // code here
        int magicnum;
        int i=0;
        for(vector<int>::iterator it =arr.begin(); it !=arr.end(); it++, i++)
        {
            if(*it==i)
            {
                magicnum=*it;
		cout<<magicnum<<endl;
                return 0;
            }
        }
        return -1;
    }
int main(){
	vector<int> arr={2,3,4,6,7,5,6,7,8};
	findMagicalNumber(arr);
}	
*/

/*
int num(vector<int>& arr)
        {
            vector<int>::iterator it = arr.begin();
            int sum=0;
            if(arr.size()>1)
            {
                for(;it !=arr.end();it++)
            {
                sum=(sum*10)+*it;
            }
            }
            
            return sum;
        }
int main() {

        vector<int>arr1 = {9, 5, 4, 9};
	vector<int>arr2 = {2, 1, 4} ;
        cout<<num(arr1)<<"+"<<num(arr2)<<"="<<num(arr1)+num(arr2)<<endl;
    
}*/
/*
class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // Complete the function
        int count;
        for (vector<int>::iterator it=arr.begin();it!=arr.end(); it++)
        {
            count=0;
            for (vector<int>::iterator jit=arr.begin(); jit!=arr.end(); jit++ )
            {
                if (*it==*jit) 
                {
                 count++;   
                }
            }
            if(count==1) return *it;
        }
        return 0;
    }
};/*

/*
class Solution {
  public:
    int noOfTriangles(vector<int>& arr) {
        // Your code goes here
        int count=0;
        for (int i=0; i<arr.size()-1; i++)
        {
            for(int j=0; j<arr.size()-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int res=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=res;
                }
            }
        }
        for(vector<int>::iterator it=arr.begin(); it!=arr.end(); it++){
            for(vector<int>::iterator jit=it+1; jit!=arr.end(); jit++){
                for(vector<int>::iterator kit=jit+1; kit!=arr.end(); kit++){
                    if(*it+*jit>*kit )
                    {
                        count++;
                    }
                }}}
        return count;
    }
};
*/
/*
class Solution {
  public:
    int noOfTriangles(vector<int>& arr) {
        // Your code goes here
        int count=0;
        /*for (int i=0; i<arr.size()-1; i++)
        {
            for(int j=0; j<arr.size()-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int res=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=res;
                }
            }
        }/
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size()-2; i++)
        {
            for(int j=i+1; j<arr.size()-1; j++)
                {
                    for(int k=j+1; k<arr.size();k++)
                    {
                        if(arr[i]+arr[j]>arr[k])
                        count++;
                    }
                }
        }
        return count;
    }
}
*/

