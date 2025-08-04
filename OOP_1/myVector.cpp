#include <iostream>	

class MyVector{
	public:
		//constructor
		MyVector(unsigned int size, int num =0) : m_arr(new int[size]), m_size(size){
			for(unsigned int i=0; i<size; i++) m_arr[i]=num;
		}
		//copy constructor
		MyVector(const MyVector& other): m_arr(new int[other.m_size]), m_size(other.m_size){
			for(unsigned int i=0; i<other.m_size; i++) m_arr[i]=other.m_arr[i];
		}
		//destructor
		~MyVector(){
			delete[] m_arr;
		}

		// assigment operator
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
	MyVector resizedV(n);
	if(n>m_size){
		for(unsigned int i=0; i<m_size; i++){
			resizedV.m_arr[i]=m_arr[i];
		}
		for(unsigned int j=m_size; j<n; j++){
			resizedV.m_arr[j]=0;
		}
	}else{
		for(unsigned int i=0;i<n; i++){
			resizedV.m_arr[i]=m_arr[i];
		}
	}
	*this=resizedV;
}
int& MyVector::operator[](int index){
	return m_arr[index];
}
int  MyVector::operator[](int index) const{
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
	print(n1);

	n1.resize(8);
	print(n1);

	n1[1]=5;
	print(n1);
	
	const MyVector n2(3,5);
	print(n2);
	int x=n2[1];
	std::cout<<x<<std::endl;
	return 0;
}
