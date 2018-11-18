#include <iostream>
using namespace std;
class AC
{
	public:
		AC(int _data):m_data(_data){}
		int m_data;
};

int main()
{
	const AC *pac = new AC(10);
	const AC *pac0 = new AC(1);
	
	cout << "初始化时，m_data = " << pac->m_data << endl;
	
	pac = pac0;

	cout << "指针赋值pac0后，m_data = " << pac->m_data << endl;

	//因为定的的pac 位const类型，即指针只能指向class CA类型
	//pac->m_data =100;  //error

	AC *pac1 = const_cast<AC *> (pac);
	
	pac1->m_data = 1000;

	cout << "指针被转成非常类型的指针后，m_data = " << pac->m_data <<endl;


	//同样的为引用时
	const AC &ac = *pac;
	
	//因为定的的pac 位const类型，即指针只能指向class CA类型
	//ac.m_data =100;  //error
	
	AC &b = const_cast<AC &> (*pac);

	cout << "使用引用的形式表示 m_data = " << b.m_data << endl; 
	
	b = const_cast<AC &> (ac);
	cout << "使用引用的形式表示 m_data = " << b.m_data << endl; 

	return 0;
}
