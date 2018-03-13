#include <iostream>
#include <cstdio>
using namespace std;

bool g_InvalidInput = false;

//�ö�̬�滮ȥ������������͵�����
int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if(pData == nullptr || nLength <= 0){
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    //���ó�ֵ
    int nCurSum = 0;
    int nGreatestSum = 0x80000000;

    for(int i=0;i<nLength;i++)
    {
        //���nCurSumС��0����ô��i��������ֵ����������
        //���nCurSum����0����ô��i��������ֵ���Ǽ��ϵ�i������
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        //����ǰ��������ֵ
        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
}

// ====================���Դ���====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// ��Ч����
void Test4()
{
    Test("Test4", NULL, 0, 0, true);
}

int main()
{
    cout << "Hello world!" << endl;

    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}