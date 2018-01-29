#include <iostream>
#include <cstdio>

using namespace std;

// ====================方法1：普通递归====================
long long Fibonacci_Solution1(unsigned int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    //大于等于2的采用公式递归计算
    return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-2);
}


// ====================方法2：尾递归====================
//输入：ret1表示第n个数的值，ret2表示第n+1个数的值
long long Fibonacci_Solution2(unsigned int n, long long ret1, long long ret2)
{
    if(n == 0)
        return ret1;
    else
        return Fibonacci_Solution2(n-1, ret2 , ret1 + ret2);
}

// ====================方法2：循环迭代====================
long long Fibonacci_Solution3(unsigned n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    long long  fibNMinusOne = 1;
    long long  fibNMinusTwo = 0;
    long long  fibN = 0;
    for(unsigned int i = 2; i <= n; ++ i)
    {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

    return fibN;
}

// ====================测试代码====================
void Test(int n, int expected)
{

    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n,0,1) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);

}

int main()
{
    cout << "Hello world!" << endl;

    //普通递归需要的时间非常的长
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);
    return 0;
}
