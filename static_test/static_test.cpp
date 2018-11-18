#include <stdio.h>
#include <iostream>

using namespace std;


class StaticA{
	public:
		void show(){m_value++; cout<<m_value<<endl;};
	private:
		static int m_value;
};

int StaticA::m_value = 0;

int main(int arg, char** agrv) {

	StaticA sa;

	int cnt=10;
	while(cnt >0){
	sa.show();
	cnt--;
	}

	return 0;
}
