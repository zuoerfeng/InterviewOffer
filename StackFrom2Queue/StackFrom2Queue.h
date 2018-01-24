#include <iostream>
#include <queue>
#include <exception>
#include <stdexcept>

using namespace std;

template <typename T>
class CStack
{
public:
    CStack(void){nCount = 0;}
    ~CStack(void);

    void appendTail(const T& data);
    T deleteTail();
    int GetNum() const;

private:
    queue<T> q1;
    queue<T> q2;
    int nCount;          //���ڸ��ٶ������ж���Ԫ�أ����Ǳ����
};

template <typename T>
CStack<T>::~CStack(void){};

template <typename T>
int CStack<T>::GetNum() const
{
    return nCount;
}

template <typename T>
void CStack<T>::appendTail(const T& data)
{
    //���뵽��Ϊ�յ��Ǹ�������
    if(q1.size() == 0 && q2.size() == 0)
        q1.push(data);
    else if(q1.size() > 0 && q2.size() == 0)
        q1.push(data);
    else if(q2.size() > 0 && q1.size() == 0)
        q2.push(data);
    else
        throw runtime_error("two is not empty!");

    ++ nCount;
}

template <typename T>
T CStack<T>::deleteTail()
{
    T ret;
    if(q1.size() == 0 && q2.size() == 0)
        throw runtime_error("cannot deleteTail, is empty");

    if(q1.size() > 0 && q2.size() == 0)
    {
        //��ʼ��q1�����ݵ���q2������һ����ջ
        while(q1.size() > 1){
            T& data = q1.front();
            q1.pop();
            q2.push(data);
        }
        ret = q1.front();
        q1.pop();
        cout << ret << endl;
    }
    else if(q2.size() > 0 && q1.size() == 0)
    {
        //��ʼ��q2�����ݵ���q1������һ����ջ
        while(q2.size() > 1){
            T& data = q2.front();
            q2.pop();
            q1.push(data);
        }
        ret = q2.front();
        q2.pop();
        cout << ret << endl;
    }
    else
        throw runtime_error("two is not empty!");

    -- nCount;
    return ret;
}



