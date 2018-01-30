#include <iostream>
#include <cstdio>
using namespace std;

//右移，比较最右边的数值
//问题：负数输入会导致死循环
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

//左移：从最左边开始比较
//问题：左移的次数等于机器操作数，即32/64位
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

//减法：减1与原数据相与得到最左边的一位1的数据
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
    int actual = NumberOf1_Solution1(number);                   //输入负数，会造成死循环，因为左移负数会补1
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

    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}
