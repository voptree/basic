#include <iostream>
#include <ctime>
#include "random.h"
using namespace std;

int myrandom(int range){
	srand(time(NULL));//设置随机数种子
	for(int i = 0; i < 100; i++){
		cout<<rand()%range<<endl;
	}
	return 0;
}
