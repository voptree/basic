#include <iostream>
#include <stdio.h>

using namespace std;

class Coordinate 
{
	public:
		Coordinate(double x, double y):m_ix(x),m_iy(y){}

		double getX(){return m_ix;}
		double gety(){return m_iy;}
		void printInfo() const;
	private:
		double m_ix;
		double m_iy;

};

void Coordinate:: printInfo() const
{
	printf("(%f,%f) \n",m_ix,m_iy);
}

int main()
{
	//普通的类实例化并打印
	Coordinate coor1(1.1, 2.2);
	Coordinate &A = coor1;
	Coordinate *pA = &coor1;
	A.printInfo();
	pA->printInfo();

	//常类类型
	const Coordinate &B = coor1;

	
	const Coordinate *pB = &coor1;
	
	//无法调用，因为编译器认为这是修改数据成员
	//B.getX();
	//B.getY();

	//同样无法调用，因为编译器认为这是修改数据成员
	//pB->getX();
	//pB->getY();

 	//成员函数是const时，就可以调用
	B.printInfo();
	pB->printInfo();


	return 0;
}
