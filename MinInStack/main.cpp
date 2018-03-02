#include <iostream>
#include "StackWithMin.h"
using namespace std;

void Test(char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}


int main()
{
    cout << "Hello world!" << endl;

    //建立一个最小栈
    StackWithMin<int> stack;

    stack.push(4);
    stack.push(2);
    stack.push(3);

    Test("Test1", stack, 2);

    stack.pop();
    stack.pop();

    Test("Test2", stack, 4);
    stack.pop();

    stack.push(0);
    Test("Test3", stack, 1);

    return 0;
}
