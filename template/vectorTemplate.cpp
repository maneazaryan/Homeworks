#include <iostream>	
#include <string>
template<typename T>
class MyVector{
	int m_size;
	int m_capacity;
	T* m_arr;

	public:
		//constructor
		MyVector(int size, T value);
		//copy constructor
		MyVector(const MyVector& other);
		//destructor
		~MyVector(){delete[] m_arr;}
		//functions
		void Print();
		void Resize(int n);
		int Size() const;
		int Capacity() const;
		void Reserve(int n) ;
		void Push_back(T newmember);
		void Pop_back();
		//operators
		MyVector& operator=(const MyVector& other);
		T& operator[](int index);
		const T& operator[](int index) const;
};

template<typename T>
MyVector<T>::MyVector(int size, T value)
	{
		m_size=size;
		m_capacity=m_size*2;
		m_arr=new T[m_capacity];
		for(int i=0; i<m_size; i++)
		{
			m_arr[i]=value;
		}
	}
template<typename T>
MyVector<T>::MyVector(const MyVector& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_arr = new T[m_capacity];
	for(int i = 0; i < m_size; i++)
	{
		m_arr[i] = other.m_arr[i];
	}
}

template<typename T>
void MyVector<T>::Print()
{
	for(int i = 0; i<m_size; i++)
	{
		std::cout<<m_arr[i]<<' ';
	}
	std::cout<<std::endl;
}

template<typename T>
int MyVector<T>::Size() const
{
	return m_size;
}

template<typename T>
int MyVector<T>::Capacity() const
{
	return m_capacity;
}

template<typename T>
void MyVector<T>::Reserve(int n)
{
	if(n>m_capacity)
	{
		m_capacity=n;
		T* arr = new T[m_capacity];
		for(int i = 0 ; i<m_size; i++)
		{
			arr[i]=m_arr[i];
		}
	
		delete[] m_arr;
		m_arr=arr;
	}
}
template<typename T>
void MyVector<T>::Push_back(T newmember)
{
	if(m_size+1<m_capacity)
	{
		m_size+=1;
		m_arr[m_size-1]=newmember;
	}
	else
	{
		m_capacity*=2;
		m_size+=1;
		T* arr= new T[m_capacity];
		for(int i = 0 ; i<m_size-1; i++)
		{
			arr[i]=m_arr[i];
		}
		arr[m_size-1]=newmember;

		delete[] m_arr;
		m_arr=arr;
	}
}

template<typename T>
void MyVector<T>::Pop_back()
{
	m_size-=1;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if(this==&other) return *this;
	delete[] m_arr;
	m_size=other.m_size;
	m_capacity=other.m_capacity;
	m_arr=new T[m_capacity];
	for(int i=0; i<m_size; i++)
	{
		m_arr[i]=other.m_arr[i];
	}
	return *this;
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
	return m_arr[index];
}

template<typename T>
const T& MyVector<T>::operator[](int index) const
{
	return m_arr[index];
}

template<typename T>
void MyVector<T>::Resize(int n)
{
		if(n>m_capacity)
		{
			m_capacity=n*2;
			T* arr = new T[m_capacity];

			for( int i = 0 ; i<m_size; i++)
			{
				arr[i]=m_arr[i];	
			} 
			for(int i =m_size ; i<n ; i++)
			{
				arr[i]=static_cast<T>(0);
			}
			delete[] m_arr;
			m_arr=arr;
		}
		else if(n>m_size)
		{
			for(int i =m_size ; i<n ; i++)
			{
				m_arr[i]=static_cast<T>(0);
			}
		}
		m_size=n;
}
int main()
{
	MyVector<double>n1(2,3.2);
	MyVector<double>n2(2,4.1);
	//n1.Print();

	n1=n2;
	n1.Print();

	n1.Resize(11);
	n1.Print();
	//std::cout<<n1.size();
	std::cout<<n1.Capacity()<<std::endl;	
	n1.Reserve(34);
	std::cout<<n1.Capacity()<<std::endl;	
//	n1.Push_back(12);
//	n1.Print();

//	n1.Pop_back();
//	n1.Print();
	return 0;
}	
