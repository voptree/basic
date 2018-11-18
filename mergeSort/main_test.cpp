#include <iostream>
#include <string>
#include "testSortHelper.hpp"

using namespace std;

//归并函数
template <typename T>
void __merge(T array[], int begin_pos, int mid_pos, int end_pos){
	//创建一个新的数组用于接收排序好到子数组
	T aux[end_pos - begin_pos +1];
	for(int i =begin_pos; i <= end_pos; i++){
		aux[i-begin_pos] = array[i];
	}
	//获取两个子数组的首位置
	int i = begin_pos, j = mid_pos+1;
	for(int k = begin_pos; k <= end_pos; k++){
		
		if(i > mid_pos){//左侧排完，右侧没排完
			array[k] = aux[j-begin_pos];
			j++;
		}else if(j > end_pos){//右侧排完,左侧没排完
			array[k] = aux[i-begin_pos];
			i++;
		}else if(aux[i-begin_pos] < aux [j-begin_pos]){
			array[k] = aux[i-begin_pos];
			i++;
		}else{
			array[k] = aux[j-begin_pos];
			j++;
		}
	}
	
}


//归并排序
template <typename T>
void __mergeSort(T array[], int b_pos, int e_pos ){
	//判断pos位置
	if (b_pos >= e_pos){
		return;
	}
	int mid_pos = (b_pos + e_pos)/2;
	//0-中点位置继续归并排序
	__mergeSort(array, b_pos, mid_pos);
	//中点后-末尾继续归并排序
	__mergeSort(array, mid_pos+1, e_pos);
	//归并函数
	__merge(array, b_pos, mid_pos, e_pos);
}

//归并排序函数
template <typename T>
void mergeSort(T array[], int nsize){
	//调用子函数
	__mergeSort(array, 0, nsize-1);
	
}

int main(int argc, char** argv){
	int n = 10;
	int * myArray;
	myArray = generArray(n,1,10);
	printArray(myArray,n);
	int * newArray;
	newArray = copyArray(myArray, n);
	printArray(newArray,n);
	mergeSort(newArray,n);
	printArray(newArray,n);
	delete []myArray;
	delete []newArray;
	return 0;
}
