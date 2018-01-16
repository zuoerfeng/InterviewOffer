#include <iostream>
#include "AssignmentOperator.h"

using namespace std;

//测试1：把一个实例赋值给另外一个实例
void Test1(){
    printf("Test1 begins:\n");

    char* text = "Hello World";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;            //调用上述写的赋值运算符

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}


int main()
{
    cout << "Hello world!" << endl;

    Test1();
    Test2();
    Test3();

    return 0;
}

