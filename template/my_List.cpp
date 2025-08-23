#include <iostream>
template<typename T>
struct Node{
	T m_data;
	Node<T>* m_prev;
	Node<T>* m_next;
	Node(const T& value) : m_data(value), m_prev(nullptr), m_next(nullptr) {}
};

template<typename T>
class List{
	Node<T>* m_head; 
	Node<T>* m_tail; 
	size_t m_size;
	public:
	List();
	~List(); 
	void Print()const;
	void Push_back(const T& value);
	void Push_front(const T& value);
	void Pop_back();
	void Pop_front();
	bool Empty() const;
	size_t Get_size() const; 
	void Clear();
	T& Front();
	T& Back();
};
//constructor, destructor
template<typename T>
List<T>::List(){
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

template<typename T>
List<T>::~List(){ Clear(); } 

//functions
template<typename T>
void List<T>::Print()const
{
	Node<T>* p = m_head;	
	if(m_size == 1)
		std::cout<<p->m_data<<' ';
	else if (m_size > 1)
	{	
		while(p!=nullptr){
			std::cout<<p->m_data<<' ';
			p = p->m_next;
		}
	}
	std::cout<<std::endl;
}

	template<typename T>
void List<T>::Push_back(const T& value)
{
	m_size++;
	Node<T>* node=new Node<T>(value);
	if(m_head==nullptr)
	{
		m_head=node;
	}
	else
	{
		node->m_prev=m_tail;
		m_tail->m_next=node;
	}
	m_tail=node;
}

	template<typename T>
void List<T>::Push_front(const T& value)
{
	m_size++;
	Node<T>* node = new Node<T>(value);
	if(m_head==nullptr)
	{
		m_head = node;
		m_tail = node;
	}
	else
	{
		node->m_next=m_head;
		m_head->m_prev=node;
		m_head=node;
	}
}

template<typename T>
void List<T>::Pop_back(){

	if(m_size==1)
	{
		delete m_head;
		m_size--;
		return;	
	}
	else if(m_size>1){

		Node<T>* last = m_tail;
		m_tail=last->m_prev;
		m_tail->m_next= nullptr;

		m_size--;
		delete last;
	}
}

template<typename T>
void List<T>::Pop_front()
{
	if(m_size==1)
	{
		delete m_head;
		m_size--;
		return;
	}
	else if(m_size>1){
		Node<T>* first = m_head;
		m_head=first->m_next;
		m_head->m_prev=nullptr;

		delete first;
		m_size--;
	}
}

template<typename T>
bool List<T>::Empty() const
{
	return m_size==0;
}

template<typename T>
size_t List<T>::Get_size() const
{
	return m_size;
}

template<typename T>
void List<T>::Clear()
{	
	while(m_size>0 )
	{
		Pop_back();
	}
}

template<typename T>
T& List<T>::Front()
{
	return m_head->m_data;
}

	template<typename T>
T& List<T>::Back()
{
	return m_tail->m_data;
}

int main()
{
	List<int> n1;
	n1.Push_back(12);
	n1.Push_front(5);
	n1.Print();
	n1.Pop_back();
	std::cout<<"after pop_back" <<std::endl;
	n1.Print();
	n1.Push_front(6);
	n1.Push_back(4);
	n1.Print();
	n1.Pop_front();
	std::cout<<"after pop_front" <<std::endl;
	n1.Print();
	std::cout<<"Size is : "<<n1.Get_size()<<std::endl;	
	n1.Clear();
	n1.Print();
	std::cout<<"Size is : "<<n1.Get_size()<<std::endl;	
	return 0;
}	
