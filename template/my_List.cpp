#include <iostream>
template<typename T>
struct Node{
	T m_data;
	Node<T>* m_prev;
	Node<T>* m_next;
	Node(const T& value) : m_data(value), m_prev(nullptr), m_next(nullptr) {}
	Node() : m_data(0), m_prev(nullptr), m_next(nullptr) {}
};

template<typename T>
class List{
	Node<T>* m_head; 
	Node<T>* m_tail; 
	Node<T>* m_end;
	size_t m_size;
	public:
		List();
		~List(); 
		void print()const;
		void push_back(const T& value);
		void push_front(const T& value);
		void pop_back();
		void pop_front();
		bool empty() const;
		size_t size() const; 
		void clear();
		T& front();
		T& back();
		class iterator;
		iterator begin(){return m_head;};
		iterator end(){return m_end;};
};
//constructor, destructor
template<typename T>
List<T>::List(): m_head(nullptr), m_tail(nullptr), m_size(0){
	m_end = new Node<T>();
}

template<typename T>
List<T>::~List(){ clear(); } 

//functions
template<typename T>
void List<T>::print()const
{
	Node<T>* p = m_head;	
	if(m_size == 1)
		std::cout << p->m_data<<' ';
	else if (m_size > 1)
	{
		while(p!= m_end){
			std::cout << p->m_data<<' ';
			p = p->m_next;
		}
	}
	std::cout<<std::endl;
}

template<typename T>
void List<T>::push_back(const T& value)
{
	m_size++;
	Node<T>* node=new Node<T>(value);
	if(m_head==nullptr && m_size==1)
	{
		m_head=node;
	}
	else
	{
		node->m_prev=m_tail;
		m_tail->m_next=node;
	}
	m_tail=node;
	node->m_next = m_end;
	m_end->m_prev = node;
}

template<typename T>
void List<T>::push_front(const T& value)
{
	m_size++;
	Node<T>* node = new Node<T>(value);
	if(m_head==nullptr && m_size==1)
	{
		node->m_next=m_end;
		m_end->m_prev=node;
		m_tail = node;
	}
	else
	{
		node->m_next=m_head;
		m_head->m_prev=node;
	}
	m_head = node;
}

template<typename T>
void List<T>::pop_back(){
	if(m_size==1)
	{
		delete m_head;
	}
	else if(m_size>1)
	{
		Node<T>* last = m_tail;
		m_tail=last->m_prev;
		m_end->m_prev=m_tail;
		m_tail->m_next= m_end;
		delete last;
	}
	m_size--;
}

template<typename T>
void List<T>::pop_front()
{
	if(m_size==1)
	{
		delete m_head;
	}
	else if(m_size>1){
		Node<T>* first = m_head;
		m_head=first->m_next;
		m_head->m_prev=nullptr;
		delete first;
	}
	m_size--;
}

template<typename T>
bool List<T>::empty() const{return m_size==0;}

template<typename T>
size_t List<T>::size() const{return m_size;}

template<typename T>
void List<T>::clear()
{	
	delete m_end;
	while(m_size>0 ) pop_back();
}

template<typename T>
T& List<T>::front(){return m_head->m_data;}

template<typename T>
T& List<T>::back(){return m_tail->m_data;}

template<typename T>
class List<T>::iterator
{
	private:
		Node<T>* m_ptr;
	public:
		iterator(Node <T>* p = nullptr): m_ptr(p) {};
		T& operator*(){ return m_ptr -> m_data;}
		T* operator->(){ return &(m_ptr -> m_data);}

		// Increment / Decrement
		iterator& operator++()
		{
			if(m_ptr->m_next!=nullptr)
				m_ptr=m_ptr->m_next;
			return *this;
		}
		iterator& operator--()
		{
			if(m_ptr->m_prev!=nullptr)
				m_ptr=m_ptr->m_prev;
			return *this;
		}

		// Comparison
		bool operator==(const iterator& other) const
		{
			return m_ptr==other.m_ptr;
		}
		bool operator!=(const iterator& other) const
		{
			return m_ptr!=other.m_ptr;
		}
		bool operator<(const iterator& other) const
		{
			return m_ptr<other.m_ptr;
		}
		bool operator>(const iterator& other) const
		{
			return m_ptr<other.m_ptr;
		}
};
int main()
{
	List<int> n1;
	n1.push_back(1);
	n1.push_back(2);
	n1.push_front(5);
	n1.push_front(6);
	n1.push_back(4);
	n1.print();
	std::cout<<"Size is : "<<n1.size()<<std::endl;	
	n1.pop_back();
	std::cout<<"after pop_back" <<std::endl;
	n1.print();
	n1.pop_front();
	std::cout<<"after pop_front" <<std::endl;
	List<int>::iterator it = n1.begin() ;
	for(auto it= n1.begin(); it != n1.end(); ++it) std::cout<<*it << ' ';
	std::cout<<"\n"<<std::endl;
	std::cout<<"*it  "<<*(it)<<std::endl;
	std::cout<<"*++it  "<<*(++it)<<std::endl;
	std::cout<<"*--it  "<<*(--it)<<std::endl;

	std::cout<<"Front is : "<<n1.front()<<std::endl;	
	std::cout<<"Size is : "<<n1.size()<<std::endl;	
	n1.clear();
	n1.print();
	std::cout<<"Size is : "<<n1.size()<<std::endl;	
	return 0;
}	
