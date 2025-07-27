#include <iostream>	
#include <vector>

int recF(int n, std::vector<int>& v)
{
	if(n==0) {
		v[n]=0;
		return v[n];}
	if(n==1){ 
		v[n]=5; 
		return v[n];}
	if(n==2) {	
		v[n]=3; 
		return v[n];}
	if(n==3){
		v[n]=4; 
		return v[n];}
	if(n==4) {
		v[n]=4; 
		return v[n];}
	if(v[n]== -1){ 
		v[n]=recF(n-5,v)*recF(n-4,v)+recF(n-2, v);
		return v[n];}
	else{
		return v[n];}
}
int print(int n, std::vector<int>& v, int i =0 )
{
	if(i>n) return i;
	std::cout<<recF(i,v)<<' ';
	return print(n,v,i+1);
}
int main()
{
	int n;
	std::cout<<"Enter a number"<<std::endl;
	std::cin>>n;
	std::vector<int>v(n+1,-1);
	print(n,v);
	return 0;
}	
