#include <iostream>	
class Animal {
public:
   virtual void eat() { std::cout << "eat\n"; }
};

class Dog : public Animal {
public:
  void bark() {std::cout << "bark\n";}
};

void BarkIfPossible(Animal* animal) {
	Dog* d =dynamic_cast<Dog*>(animal);
	if(d!=nullptr){
		d->bark();
	}else{
		std::cout<<"it isn't dog"<<std::endl;
	}
}
int main()
{
	Dog* n=new Dog;
	Animal* n1=new Dog;
	Dog n2;
	Animal n3;

	std::cout<<"n"<<std::endl;
	BarkIfPossible(n);

	std::cout<<"n1"<<std::endl;
	BarkIfPossible(n1);

	std::cout<<"n2"<<std::endl;
	BarkIfPossible(&n2);

	std::cout<<"n3"<<std::endl;
	BarkIfPossible(&n3);
	
	delete n;
	delete n1;
	return 0;
}	
