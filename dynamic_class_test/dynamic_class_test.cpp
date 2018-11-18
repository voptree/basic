#include <iostream>
#include <stdio.h>

using namespace std;

class A
{

	public:
	virtual void f(){}
};

class B
{

	public:
		//virtual void b(){}
		
		//virtual void f(){}
};

int main()
{

	A *pA = new A();

	B *pB = new B();

	void *pV = dynamic_cast<void *> (pA);
	pV = dynamic_cast<void *> (pB);
	return 0;
}
