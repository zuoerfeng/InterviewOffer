#include <iostream>
#include <cstdio>
using namespace std;

bool g_InvalidInput = false;

//用动态规划去解决最大子数组和的问题
int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if(pData == nullptr || nLength <= 0){
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    //设置初值
    int nCurSum = 0;
    int nGreatestSum = 0x80000000;

    for(int i=0;i<nLength;i++)
    {
        //如果nCurSum小于0，那么第i数组的最大值就是它本身
        //如果nCurSum大于0，那么第i数组的最大值就是加上第i个数字
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        //保存前数组的最大值
        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
}

// ====================测试代码====================
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

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
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
