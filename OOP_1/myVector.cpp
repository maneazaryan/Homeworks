#include <iostream>	

class MyVector{
	public:
		//constructor
		MyVector(unsigned int size, int num=0): m_size(size), m_arr(new int[size]){
			for(unsigned int i=0; i<size; i++) m_arr[i]=num;
		}	
		//copy constructor
		MyVector(const MyVector& other):m_size(other.m_size), m_arr(new int[other.m_size]){
			for(unsigned int i=0; i<m_size; i++) m_arr[i]=other.m_arr[i];
		}
		//destructor
		~MyVector(){
			delete[] m_arr;
		}
		// assigment operatori
		MyVector& operator = (const MyVector& other){
			if(this==&other){
				return *this;
			}
			delete[] m_arr;

			m_size= other.m_size;
			m_arr=new int[m_size];
			for(unsigned int i=0; i<m_size; i++){
				m_arr[i]=other.m_arr[i];
			}
			return *this;
		}
		void resize(unsigned int n);

		// Enables access to array elements using the [] operator.
		int& operator[](int index);
		int operator[](int index) const;

		// Returns the size of the array.
		unsigned int size() const;

	private:
		int* m_arr;
		unsigned int m_size;
};
void MyVector::resize(unsigned int n){
	int* resizedV= new int[n];
	if(n>m_size){
		for(unsigned int i=0; i<m_size; i++){
			resizedV[i]=m_arr[i];
		}
		for(unsigned int j=m_size; j<n; j++){
			resizedV[j]=0;
		}
	}else{
		for(unsigned int i=0;i<n; i++){
			resizedV[i]=m_arr[i];
		}
	}
	delete[] m_arr;
	m_arr=resizedV;
	m_size=n;
	
}
int& MyVector::operator[](int index){
	return m_arr[index];
}
int MyVector::operator[](int index) const{
	return m_arr[index];
}
unsigned int MyVector::size() const{
	return m_size;
}
void print(const MyVector& arr){
	for(unsigned int i =0; i< arr.size(); i++) std::cout<<arr[i]<< ' ';
	std::cout<<std::endl;
}
int main()
{
	MyVector n1(4,2);
	std::cout<<"array n1"<<std::endl;
	print(n1);

	n1.resize(8);
	std::cout<<"n1 after resizing"<<std::endl;
	print(n1);

	n1[1]=5;
	std::cout<<"n[1] after modifing 5"<<std::endl;
	print(n1);
	
	MyVector n3(8,7);
	std::cout<<"array n3"<<std::endl;
	print(n3);
	
	std::cout<<"using operator = n1=n3"<<std::endl;
	n1=n3;
	print(n1);

	std::cout<<"array n2"<<std::endl;
	const MyVector n2(3,5);
	print(n2);
	int x=n2[1];
	std::cout<<x<<std::endl;
	return 0;
}
