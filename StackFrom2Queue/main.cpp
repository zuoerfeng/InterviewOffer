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

    cout<<"Ԫ�صĸ�����"<<stack.GetNum()<<endl;

    cout<<"��ջ������ȳ�����99��"<<endl;
    stack.deleteTail();

    cout<<"Ԫ�صĸ�����"<<stack.GetNum()<<endl;
    stack.appendTail(777);
    cout<<"Ԫ�صĸ�����"<<stack.GetNum()<<endl;

    cout<<"��ջ������ȳ�����777��"<<endl;
    stack.deleteTail();
    cout<<"Ԫ�صĸ�����"<<stack.GetNum()<<endl;

    stack.deleteTail();
    stack.deleteTail();
    cout<<"Ԫ�صĸ�����"<<stack.GetNum()<<endl;

    stack.deleteTail();
    return 0;
}
