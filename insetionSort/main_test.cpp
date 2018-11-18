#include <iostream>
#include <algorithm>
#include <ctime>
#include <assert.h>
#include <string>

using namespace std;

template <typename T>
void printArray(T  array[], int nsize){
	for(int i = 0; i < nsize; i++){
		cout<< array[i]<<" ";
	}
	cout<<endl;
}

template <typename T>
void selectionSort(T array[], int nsize){
	for(int i = 0; i < nsize; i++){
		int min_pos = i;
		for(int j = i; j < nsize; j++){
			if(array[j] < array[min_pos]){
				min_pos = j;
			}
		}
		if(i != min_pos)
			swap(array[i], array[min_pos]);
	}
}

template <typename T>
void insertionSort0(T  array[], int nsize){
	//遍历所有元素
	for(int i = 1; i < nsize; i++){
		//如果当前元素位置大于后面一位元素位置，则两者进行交换
		if(array[i] < array[i-1]){
			//swap(array[i],array[i-1]);
			for(int j = i ; j > 0; j--){
				if(array[j-1] > array[j]){
					swap(array[j-1],array[j]);
				} else{
					break;
				}
			}	
		}
	}
}

template <typename T>
void insertionSort(T  array[], int nsize){
	//遍历所有元素
	for(int i = 1; i < nsize; i++){
		//如果当前元素位置大于后面一位元素位置，则两者进行交换
		if(array[i] < array[i-1]){
			//swap(array[i],array[i-1]);
			for(int j = i ; j > 0; j--){
				if(array[j-1] > array[j]){
					T tmp;
					tmp = array[j];
					array[j] = array[j-1];
					array[j-1] = tmp;
				} else{
					break;
				}
			}	
		}
	}
}

int * generArray(int nsize, int limitL, int limitR){
	assert(nsize > 0);
	assert((limitR > limitL));
	srand(time(NULL));
	int * array = new int[nsize];
	for(int i = 0; i < nsize; i++){
		int value = (rand()%(limitR-limitL+1)) + limitL;
		array[i] = value;
	}
	return array;
}



template <typename T>
int * copyArray(T array[], int nsize){
	int * newArray = new int[nsize];
	copy(array,array+nsize,newArray);
	return newArray;
}

template <typename T>
bool checkArray(T array[], int nsize){
	for(int i = 0; i < nsize-1; i++){
		if(array[i]> array[i+1]){
			return false;
		}
	}
	return true;
}

template <typename T>
void testSort(string sortName,T array[], int nsize, void(*func)(T [], int)){
	clock_t start_time, ending_time;
	start_time = clock();
	func(array,nsize);
	ending_time = clock();
	double used_time = double(ending_time - start_time)/CLOCKS_PER_SEC;
	assert(checkArray(array, nsize));
	cout<<sortName<< " used: " << used_time<< " s"<<endl;

}

int main(int argc, char** argv){
	int n = 100000;
	int myArray[10]  = {10,9,8,7,6,5,4,3,2,1};
	int * myArray1 = generArray(n,1,n);
	int * myArray2 = copyArray(myArray1,n);
	int * myArray3 = copyArray(myArray1,n);
	//printArray(myArray, 10);
	//insertionSort(myArray,10);
	//selectionSort(myArray,n);
	testSort("selectionSort",myArray1,n, selectionSort);
	testSort("insetionSort0",myArray2,n, insertionSort0);
	testSort("insetionSort",myArray3,n, insertionSort);
	//printArray(myArray, 10);
	delete []myArray1;
	delete []myArray2;
	delete []myArray3;
	return 0;
}
