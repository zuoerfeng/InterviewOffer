#include <iostream>
#include <cstdio>
using namespace std;


// ====================算法1的代码====================

bool IsUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;

    return (number == 1) ? true : false;
}

int GetUglyNumber_Solution1(int index)
{
    if(index <= 0)
        return 0;

    int number = 0;
    int uglyFound = 0;
    while(uglyFound < index)
    {
        ++number;

        if(IsUgly(number))
        {
            ++uglyFound;
        }
    }
    return number;
}

// ====================算法2的代码====================

int Min(int number1, int number2, int number3);

int GetUglyNumber_Solution2(int index)
{
    if(index <= 0)
        return 0;

    int *pUglyNumbers = new int[index];    //创建一个数组用来存放丑数
    pUglyNumbers[0] = 1;                   //第一个丑数为1
    int nextUglyIndex = 1;                 //丑数的计数值

    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;

    while(nextUglyIndex < index)
    {
        int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);   //取乘法之后的最小值，作为下一个值
        pUglyNumbers[nextUglyIndex] = min;

        while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])               //不是所有的值都需要乘2，只需要对那么那些大于的当前最大值的数乘计数即可。
            ++pMultiply2;
        while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply3;
        while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply5;

        ++nextUglyIndex;
    }

    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete[] pUglyNumbers;
    return ugly;
}

int Min(int number1, int number2, int number3)
{
    int min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;

    return min;
}

// ====================测试代码====================
void Test(int index, int expected)
{
    if(GetUglyNumber_Solution1(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");

    if(GetUglyNumber_Solution2(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}


int main()
{
    cout << "Hello world!" << endl;

    Test(1, 1);
    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}
