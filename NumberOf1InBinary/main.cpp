#include <iostream>
#include <cstdio>
using namespace std;

//���ƣ��Ƚ����ұߵ���ֵ
//���⣺��������ᵼ����ѭ��
int NumberOf1_Solution1(int n)
{
    int count = 0;
    while(n){
        if(n & 1)
            ++ count;
        n = n >> 1;
    }
    return count;
}

//���ƣ�������߿�ʼ�Ƚ�
//���⣺���ƵĴ������ڻ�������������32/64λ
int NumberOf1_Solution2(int n)
{
    int count = 0;
    unsigned int flag =  1;
    while(flag){
        if(n & flag)
            ++ count;
        flag = flag << 1;
    }
    return count;
}

//��������1��ԭ��������õ�����ߵ�һλ1������
int NumberOf1_Solution3(int n)
{
    int count = 0;
    while(n){
        ++ count;
        n = n & (n-1);
    }
    return count;
}

void Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution1(number);                   //���븺�����������ѭ������Ϊ���Ƹ����Ჹ1
    if(actual == expected)
        printf("Solution1: Test for %p passed.\n", number);
    else
        printf("Solution1: Test for %p failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if(actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    actual = NumberOf1_Solution3(number);
    if(actual == expected)
        printf("Solution3: Test for %p passed.\n", number);
    else
        printf("Solution3: Test for %p failed.\n", number);

    printf("\n");
}

int main()
{
    cout << "Hello world!" << endl;

    // ����0���ڴ��������0
    Test(0, 0);

    // ����1���ڴ��������1
    Test(1, 1);

    // ����10���ڴ��������2
    Test(10, 2);

    // ����0x7FFFFFFF���ڴ��������31
    Test(0x7FFFFFFF, 31);

    // ����0xFFFFFFFF�����������ڴ��������32
    Test(0xFFFFFFFF, 32);

    // ����0x80000000�����������ڴ��������1
    Test(0x80000000, 1);

    return 0;
}
