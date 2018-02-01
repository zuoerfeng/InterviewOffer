#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory>
#include <stdexcept>
using namespace std;

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================����һ====================
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

// �ַ���number��ʾһ�����֣��� number������1������00/01/02.....10/11/12/13.....20/21/22.....90/91/92...99/100 ������λ���
// ������ӷ�������򷵻�true������Ϊfalse
bool Increment(char* number)
{
    bool isOverflow = false;
    int nTakeOver = 0;                              //nTakeOver��ʾ��λֵ
    int nLength = strlen(number);

    //��һ��ѭ����������λ����λ
    for(int i = nLength - 1; i >= 0; i --)
    {
        int nSum = number[i] - '0' + nTakeOver;      //nsum��ʾ��ǰ��һλ������ֵ
        if(i == nLength - 1)
            nSum ++;   //����һλ

        //�ж��ַ�����ĳһ��λ�Ƿ�ӵ���10����10��Ҫ��1
        if(nSum >= 10)
        {
            if(i == 0)          //���λ��10�������Ѿ��ﵽ�����ֵ
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

// ====================��������====================
// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
// ��ӡ��������֣������Կ�ͷ��0
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

// ====================������====================
//����0-9��ȫ���еķ��������������ÿһλȫ���У��������ֵ�����δ�0-nλ���
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

// ====================���Դ���====================
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
