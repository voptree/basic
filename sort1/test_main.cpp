#include <iostream>
#include "selectionSort.hpp"
using namespace std;

void test_print(int i = 10, int j = 20){
	printf("i:%d, j:%d\n",i,j);
}
int main(int argc, char **argv)
{

    selectionSort::test_sort();
    test_print(30);
    return 0;
}
