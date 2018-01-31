#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

//全局变量
bool g_InvalidInput = false;   //异常信息的全局变量

//函数的声明
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, int exponent);
double Power(double base, int exponent);
double PowerWithUnsignedExponent_new(double base, int exponent);

//最简单的乘方运算
//缺点：没有考虑到小于1，基数等于0的情况
double PowerWithUnsignedExponent(double base, int exponent)
{
    double result = 1.0;
    for(int i = 1; i <= exponent; ++i)
        result *= base;

    return result;
}

//考虑边界条件的乘方运算
double Power(double base, int exponent)
{
    g_InvalidInput = false;

    //首先判断输入信息是否有问题（base = 0、exponent < 0）0的负次幂是没有意义的
    if(equal(base,0.0) && exponent < 0){
        g_InvalidInput = true;
        return 0.0;
    }

    //对所有的指数进行求绝对值
    unsigned int absExponent =  (unsigned int)(exponent);
    if(exponent < 0){
        absExponent =  (unsigned int)(-exponent);
    }

    //计算乘方
    //double result = PowerWithUnsignedExponent(base,absExponent);
    double result = PowerWithUnsignedExponent_new(base,absExponent);

    //负指数需要进行求倒数
    if(exponent < 0)
        result = (1.0)/result;

    return result;
}

bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001)
        && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

//优化乘方次数的乘方运算
double PowerWithUnsignedExponent_new(double base, int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent_new(base, exponent >> 1);
    result *= result;

    if((exponent & 0x1) == 1)    //基数则需要最后乘上一个base
        result *= base;

    return result;
}

// ====================测试代码====================
void Test(double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if(abs(result - expectedResult) < 0.00000001
        && g_InvalidInput == expectedFlag)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}


int main()
{
    cout << "Hello world!" << endl;

    // 底数、指数都为正数
    printf("Test1 begins.\n");
    Test(2, 3, 8, false);

    // 底数为负数、指数为正数
    printf("Test2 begins.\n");
    Test(-2, 3, -8, false);

    // 指数为负数
    printf("Test3 begins.\n");
    Test(2, -3, 0.125, false);

    // 指数为0
    printf("Test4 begins.\n");
    Test(2, 0, 1, false);

    // 底数、指数都为0
    printf("Test5 begins.\n");
    Test(0, 0, 1, false);

    // 底数为0、指数为正数
    printf("Test6 begins.\n");
    Test(0, 4, 0, false);

    // 底数为0、指数为负数
    printf("Test7 begins.\n");
    Test(0, -4, 0, true);


    return 0;
}
