#include <iostream>
#include <string>
#include <vector>
class Animal;
class Dog;
class Cat;

class Visitor{
    public:
        virtual void makeNoice(Cat* a) = 0;
        virtual void makeNoice(Dog* a) = 0;
};
class Animal{
    std::string m_name;
    public:
        Animal(std::string name): m_name(name){};
        virtual const std::string& GetName() const
            {
				return m_name;
			}
        virtual void accept(Visitor& v) = 0;
};
class Dog: public Animal{
    public:
        Dog(std::string name ): Animal(name){}
        void accept(Visitor& v)override
            {
				v.makeNoice(this);
			}    
};
class Cat: public Animal{
    public:
        Cat(std::string name) : Animal(name){}
        void accept(Visitor& v) override
        {
			v.makeNoice(this);
		}
};

class GreenText : public Visitor{
    public:
        void makeNoice(Cat* a)  
        {
            std::cout<<"\033[32m"<<a->GetName()<<" Meow"<<"\033[0m"<<std::endl;
        }
        void makeNoice(Dog* a)  
        {
            std::cout<<"\033[32m"<<a->GetName()<<" Haf"<<"\033[0m"<<std::endl;
        }
};
class RedText : public Visitor{
    public:
        void makeNoice(Cat* a) override
        {
            std::cout<<"\033[31m"<<a->GetName()<<" Meow"<<"\033[0m"<<std::endl;
        }
        void makeNoice(Dog* a) override
        {
            std::cout<<"\033[31m"<<a->GetName()<<" Haf"<<"\033[0m"<<std::endl;
        }
};
int main() {
	std::vector<Animal*> v = 
	{
		new Dog("Max"),
		new Dog("Miki"),
		new Cat("Tom"),
		new Cat("Mishka")
	};
    
    RedText r;
    GreenText g;
	for(Animal* a : v)
  		a->accept(r);

	for(Animal* a : v)
  		a->accept(g);

	for (Animal* a : v )
		delete a;
    return 0;
}
