#include <iostream>
#include <cstdio>
#include "Queue.h"

using namespace std;

void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}


int main()
{
    cout << "Hello world!" << endl;

    CQueue<char> queue;      //ע��ģ����ֻ��ʵ������ʱ�򣬲Ż������ض����͵Ĵ���

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');

    head = queue.deleteHead();
    Test(head, 'e');

    return 0;
}
