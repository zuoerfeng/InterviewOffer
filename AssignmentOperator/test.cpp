#include <iostream>
#include "AssignmentOperator.h"

using namespace std;

//����1����һ��ʵ����ֵ������һ��ʵ��
void Test1(){
    printf("Test1 begins:\n");

    char* text = "Hello World";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;            //��������д�ĸ�ֵ�����

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// ��ֵ���Լ�
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

// ������ֵ
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

