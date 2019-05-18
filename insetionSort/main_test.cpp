#include<string>
#include<iostream>
using namespace std;

int main ( )
{
	int i = 10, j = 10;
	cout<<"step 1: " << "i = " << i << " j = " << j << endl;
	int a, b;
	a = i++;
	b = ++j;
	cout<<"step 2: a=i++;  b=++j;"<<endl;
	cout<<"=========result=========="<<endl;
	cout<<"i = " << i << " j = " << j << endl;
	cout<<"a = " << a << " b = " << b << endl;
	cout<<"========================="<<endl;
	return 0;
}
