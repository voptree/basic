#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

struct Student{
	string name;
	int score;
	bool operator > ( Student & stu){
		//return (score > stu.score);
		return score != stu.score ? score > stu.score : name > stu.name;
	}
	friend ostream & operator<<(ostream & os, const Student &stu){
		return os<<"student name:"<< stu.name << ", student score:" << stu.score<<endl;
		return os;
	}
};
//模板函数，打印T类型数组
template <typename T>
void printArray(T array[], int n){
	for(int i = 0; i < n ; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

//选择排序算法
template <typename T>
void selectSort(T array[], int size_n){
	for(int i = 0; i < size_n; i++){
		int min_pos=i;
		for(int j = i+1; j < size_n; j++){
			if(array[min_pos] > array[j]){
				min_pos = j;
			}
		}
		if (i != min_pos){
			swap(array[i],array[min_pos]);
		}
	}

}

//自动生成随机数组
int * generRandomArray(int nsize, int rangeLeft, int rangeRight){
	assert( (rangeRight-rangeLeft) >0 );
	srand(time(NULL));//设置随机数种子
	int * array = new int[nsize];
	for(int i = 0; i < nsize; i++){
		array[i] = (rand()%(rangeRight-rangeLeft+1))+rangeLeft;
	}
	return array;
}


template <typename T>
bool isSorted(T array[],int nsize){
	for(int i = 0; i < nsize-1; i++){
		if(array[i] > array[i+1]){
			return false;
		}
	}
	return true;
}
//测试排序时间
template <typename T>
void testSort(string sortName, T array[],int n,void(*sort)(T [], int size_n)){
	clock_t start_time,end_time;
	start_time = clock();
	sort(array, n);
	end_time = clock();

	assert(isSorted(array, n));
	double use_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
	cout <<sortName <<" use " << use_time <<" s"<<endl;
}


int main(int argc, char** argv){

	//int array[10] = {10,9,8,7,6,5,4,3,2,1};
	//char array[10] = {'j','i','h','g','f','e','d','c','b','a'};
	string array[10] = {"j","i","h","g","f","e","d","c","b","a"};
	//selectSort(array, 10);
	//for(int i = 0; i < 10; i++){
	//	cout<<array[i]<<", ";
	//}
	//cout<<endl;

	//Student array_s[4] = {{"A",100},{"B",99},{"C",99},{"D",97}};
	//selectSort(array_s,4);
	//	for(int i  = 0; i < 4; i++){
	//	cout<<"name: "<<array_s[i].name<<", score: "<<array_s[i].score<<endl;
	//	}

		int * myArray = generRandomArray(100000,1,1000);
		testSort("selectionSort", myArray, 100000,selectSort );
		delete []myArray;
	return 0;
}

