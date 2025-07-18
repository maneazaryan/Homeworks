#include <iostream>
#include <vector>

void arrMax(std::vector<int>& varr)
{
        std::vector<int>::iterator it = varr.begin();
        int count ;
        for(;it != varr.end(); it++)
        {
                count =0; 
                for(int i =1; i<=*it; i++)
                {
                        if(*it % i ==0)count++;
                        if(count>2)break;
    
                }
                if(count==2)std::cout<< *it << ' ' ;
        }
        std::cout << std::endl;
}
int main()
{
        std::vector<int>arr;
        int num , n;
        std::cin>>n;
        for(int i=0; i<n; i++)
        {
                std::cin>>num ;
                arr.push_back(num);
        }
        arrMax(arr);
        return 0;
}
~        
