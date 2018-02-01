#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory>
#include <stdexcept>
using namespace std;

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================方法一====================
void Print1ToMaxOfNDigits_1(int n)
{
    if(n <= 0){
        throw runtime_error("the number is < 0");
        return;
    }

    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';

    while(!Increment(number)){
        PrintNumber(number);
    }
}

// 字符串number表示一个数字，在 number上增加1。例如00/01/02.....10/11/12/13.....20/21/22.....90/91/92...99/100 输出最高位溢出
// 如果做加法溢出，则返回true；否则为false
bool Increment(char* number)
{
    bool isOverflow = false;
    int nTakeOver = 0;                              //nTakeOver表示进位值
    int nLength = strlen(number);

    //做一个循环，遍历低位到高位
    for(int i = nLength - 1; i >= 0; i --)
    {
        int nSum = number[i] - '0' + nTakeOver;      //nsum表示当前这一位的整数值
        if(i == nLength - 1)
            nSum ++;   //递增一位

        //判断字符串的某一个位是否加到了10，满10需要进1
        if(nSum >= 10)
        {
            if(i == 0)          //最高位满10，表明已经达到了最大值
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i = 0; i < nLength; ++ i)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if(!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}

// ====================方法二====================
//利用0-9的全排列的方法进行输出，对每一位全排列，输出所有值，依次从0-n位输出
void Print1ToMaxOfNDigits_2(int n)
{
    if(n <= 0){
        throw runtime_error("the number is < 0");
        return;
    }

    char* number = new char[n + 1];
    number[n] = '\0';

    for(int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if(index == length - 1){
        PrintNumber(number);
        return;
    }

    for(int i = 0; i < 10; i++){
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("Test for %d ends.\n", n);
}


int main()
{
    cout << "Hello world!" << endl;

    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
