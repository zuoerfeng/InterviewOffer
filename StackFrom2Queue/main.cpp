#include <iostream>
#include "StackFrom2Queue.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    CStack<int> stack;
    stack.appendTail(88);
    stack.appendTail(44);
    stack.appendTail(99);

    cout<<"元素的个数："<<stack.GetNum()<<endl;

    cout<<"出栈，后进先出：出99："<<endl;
    stack.deleteTail();

    cout<<"元素的个数："<<stack.GetNum()<<endl;
    stack.appendTail(777);
    cout<<"元素的个数："<<stack.GetNum()<<endl;

    cout<<"出栈，后进先出：出777："<<endl;
    stack.deleteTail();
    cout<<"元素的个数："<<stack.GetNum()<<endl;

    stack.deleteTail();
    stack.deleteTail();
    cout<<"元素的个数："<<stack.GetNum()<<endl;

    stack.deleteTail();
    return 0;
}
