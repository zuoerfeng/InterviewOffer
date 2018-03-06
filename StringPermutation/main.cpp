#include <iostream>
#include "cstdio"
using namespace std;

void Permutation(char* pStr, char* pBegin);

void PermutationStr(char* pStr)
{
    if(pStr == NULL)
        return;

    Permutation(pStr, pStr);
}

//ʹ�õݹ顢��̬�滮��˼��ʵ��ȫ����
void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
        printf("%s\n", pStr);
    else{
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh){
            //���������ַ��������ַ���
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin + 1);

            //�ݹ������֮��Ҫ��������
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}


// ====================���Դ���====================
void Test(char* pStr)
{
    if(pStr == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    PermutationStr(pStr);

    printf("\n");
}

int main()
{
    cout << "Hello world!" << endl;

    Test(NULL);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);


    return 0;
}
