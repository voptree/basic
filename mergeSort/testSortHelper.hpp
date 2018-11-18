#include <iostream>
#include <algorithm>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <string>

using namespace std;


template <typename T>
T* copyArray(T array[], int nsize){
	new newArray[nsize];
	std::copy(array[0], array[0]+nsize-1, newArray[0]);
	return &newArray;
}

template <typename T>
void printArray(T array[], int nsize){
	for(int i = 0; i < nsize; i++){
		cout<<"array["<<i<<"] :" <<array[i];
	}
	cout<<endl;
}

template <typename T>
T *generArray( int nsize, int miniest_val){
	assert(val_left >= val_right);
	assert(n < 0);
	new array[nsize];
	unsigned long seed = time(NULL)
	srand(seed);
	for(int i = 0; i < nsize; i++){
		val = rand%(n+1) + val_left;
		array[i] = val;
	}
	return &array;

}
