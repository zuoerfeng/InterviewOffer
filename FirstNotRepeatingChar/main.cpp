#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

char FirstNotRepeatingChar(char* pString)
{
    if(pString == nullptr)
        return '\0';

    //建立一个hashtable表，并初始化
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

// ====================测试代码====================
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

    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入NULL
    Test(NULL, '\0');


    return 0;
}
