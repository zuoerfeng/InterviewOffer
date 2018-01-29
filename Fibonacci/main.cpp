#include <iostream>
#include <cstdio>

using namespace std;

// ====================����1����ͨ�ݹ�====================
long long Fibonacci_Solution1(unsigned int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    //���ڵ���2�Ĳ��ù�ʽ�ݹ����
    return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-2);
}


// ====================����2��β�ݹ�====================
//���룺ret1��ʾ��n������ֵ��ret2��ʾ��n+1������ֵ
long long Fibonacci_Solution2(unsigned int n, long long ret1, long long ret2)
{
    if(n == 0)
        return ret1;
    else
        return Fibonacci_Solution2(n-1, ret2 , ret1 + ret2);
}

// ====================����2��ѭ������====================
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

// ====================���Դ���====================
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

    //��ͨ�ݹ���Ҫ��ʱ��ǳ��ĳ�
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
