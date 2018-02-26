#include <iostream>
#include <cstdio>
using namespace std;

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

// ====================方法一====================
void ReorderOddEven_1(int *pData, unsigned int length)
{
    //首先进行函数输入的正确性判断
    if(pData == nullptr || length == 0)
        return;

    //设置两个指针，一个从头开始遍历，一个从尾开始遍历
    int *pBegin = pData;
    int *pEnd = pData+length-1;

    while(pBegin < pEnd)
    {
        //第一个指针向后移动，直到发现第一个偶数，并指向当前的偶数
        while(pBegin < pEnd && (*pBegin & 0x01) != 0)
            pBegin++;

        //第二个指针向前移动，直到发现第一个奇数，并指向当前的奇数
        while(pBegin < pEnd && (*pEnd & 0x01) == 0)
            pEnd--;

        //交换奇偶
        if(pBegin < pEnd){
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}


// ====================方法二====================
//增加函数指针，用来交换的判断
void ReorderOddEven_2(int *pData, unsigned int length)
{
    Reorder(pData, length, isEven);
}

//重排的函数，注意第三个参数是函数指针
void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
    if(pData == NULL || length == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd)
    {
        // 向后移动pBegin
        while(pBegin < pEnd && !func(*pBegin))
            pBegin ++;

        // 向前移动pEnd
        while(pBegin < pEnd && func(*pEnd))
            pEnd --;

        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

//增加函数指针，用来交换的判断
bool isEven(int n)
{
    return (n & 1) == 0;
}


// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEven_1(numbers, length);
    PrintArray(numbers, length);

    printf("Test for solution 2:\n");
    PrintArray(copy, length);
    ReorderOddEven_2(copy, length);
    PrintArray(copy, length);

    delete[] copy;
}


void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", NULL, 0);
}

int main()
{
    cout << "Hello world!" << endl;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
