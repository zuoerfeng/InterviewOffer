#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

char FirstNotRepeatingChar(char* pString)
{
    if(pString == nullptr)
        return '\0';

    //����һ��hashtable������ʼ��
    const int tablesize = 256;
    unsigned int hashtable[tablesize];
    for(unsigned int i = 0;i<tablesize;++ i)
        hashtable[i] = 0;

    char* pHashKey = pString;
    while(*pHashKey != '\0'){
        hashtable[*pHashKey] ++;
        pHashKey++;
    }

    pHashKey = pString;
    while(*pHashKey != '\0')
    {
        if(hashtable[*pHashKey] == 1)
            return *pHashKey;

        pHashKey++;
    }

    return '\0';
}

// ====================���Դ���====================
void Test(char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main()
{
    cout << "Hello world!" << endl;

    // ����������ԣ�����ֻ����һ�ε��ַ�
    Test("google", 'l');

    // ����������ԣ�������ֻ����һ�ε��ַ�
    Test("aabccdbd", '\0');

    // ����������ԣ������ַ���ֻ����һ��
    Test("abcdefg", 'a');

    // ³���Բ��ԣ�����NULL
    Test(NULL, '\0');


    return 0;
}
