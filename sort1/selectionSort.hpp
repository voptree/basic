#include <algorithm>
#include <stdio.h>
#include<cstring>

namespace selectionSort{
void sort1(int array[], int num)
{
    int min, pos;
    for (int i = 0; i < num; i++)
    {
        min = array[i];
        for (int j = i + 1; j < num; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                pos = j;
            }
        }
        std::swap(array[i], array[pos]);
    }
}

void sort2(int *array, int num)
{

    for (int i = 0; i < num; i++)
    {
        int pos = i;
        for (int j = i + 1; j < num; j++)
        {
            if (array[j] < array[pos])
            {
                pos = j;
            }
        }
        std::swap(array[i], array[pos]);
    }
}

void test_sort()
{
    //原始数组
    int array1[10] = {3, 1, 4, 6, 8, 2, 9, 5, 10, 7};
    int* array2 = new int[10];
    printf("数组首原始sizeof:%d ,sizeof,sizeof(array1) :%d,  sizeof(array2*) : %d \n",(int)sizeof(array1[0]),(int)sizeof(array1),(int)sizeof(array2));
    memcpy(array2,array1,sizeof(array1));
    printf("原始数组为:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");
    sort1(array1, 10);
    printf("使用array[] 做为入参,输出排序结果:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array1[i]);
    }

    printf("原始数组为:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");
    printf("使用int* 做为入参\n");
    sort2(array2, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");
}
}