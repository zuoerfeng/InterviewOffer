#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//输入是字符串，找到空格并用十六进制替换,注意必须是指针（数组名传递），因为是在原址上进行修改
void ReplaceBlank(char string[], int length)
{
    if(string == nullptr || length < 0)
        return;

    //第一步遍历，找到所有的空格，计算最终移动后的字符个数
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;

    while(string[i] != '\0'){
        ++ originalLength;
        if(string[i] = ' ')
            ++ numberOfBlank;
        ++i;
    }
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    //第二步，从后向前进行遍历，不是空格的字符依次向后移，遇到的空格则添加十六进制
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;

    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
        if(string[indexOfOriginal] == ' '){
            string[indexOfNew --] = '0';
            string[indexOfNew --] = '2';
            string[indexOfNew --] = '%';
        }
        else{
            string[indexOfNew--] = string[indexOfOriginal];
        }
        -- indexOfOriginal;
    }
}

// ====================测试代码====================
void Test(char* testName, char string[], int length, char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)
        printf("passed.\n");
    else if(expected == NULL && string != NULL)
        printf("failed.\n");
    else if(strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// 传入NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
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
    Test7();
    Test8();
    Test9();

    return 0;
}
