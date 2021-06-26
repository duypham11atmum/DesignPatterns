#include <iostream>
using namespace std;

class Component{
public:
	virtual void func(int v)=0;
	virtual ~Component(){}
};
class ConcreteComp: public Component{
public:
	void func(int v){
		cout<<"Concrete COMPONENT "<<v<<endl;
	}
	~ConcreteComp(){}
};

class Decorator: public Component{
	Component* mainComp;

public:
	Decorator(Component* c){ mainComp = c; }
	void func(int v){
		mainComp->func(v);
	}
	~Decorator(){
		//delete mainComp;
	}
};


class DecoratorA: public Decorator{
public:
	DecoratorA(Component* c): Decorator(c){ }

	void func(int v){
		Decorator::func(v);
		cout<<"Addition from Decorator A"<<v*22<<endl;
	}
	~DecoratorA(){
		//delete mainComp;
	}
};
int main(int argc, char **argv) {
	cout<<"Hello World!!!"<<endl;

	ConcreteComp *c = new ConcreteComp();
	Decorator d(c);
	d.func(111);

	DecoratorA dA(c);
	dA.func(9999);

	delete c;
	return 0;
}
