#include <stack>
#include <exception>
#include <stdexcept>

using namespace std;

//����һ��ģ���࣬ʹ�õ�������ջʵ��һ������
template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    //�ڶ���ĩβ���һ��Ԫ��
    void appendTail(const T& node);

    //�ڶ��ж�ͷɾ��һ��Ԫ��
    T& deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

//ģ����Ķ��������������ͬһ��ͷ�ļ�����
template <typename T>
CQueue<T>::CQueue(void){}

template <typename T>
CQueue<T>::~CQueue(void){}

template <typename T>     //ע��ģ����ĺ������壬������ˣ�����ֵ������У������޷�ƥ�䵽������ĺ�������
void CQueue<T>::appendTail(const T& node){
    stack1.push(node);
}

template <typename T>
T& CQueue<T>::deleteHead(){
    //�ж�stack�ǲ���Ϊ�գ���Ϊ�գ���stack1�������ƶ���stack2
    if(stack2.size() <= 0)
    {
        while(stack1.size()>0){         //�ƶ�stack1����������
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0)
        throw runtime_error("queue is empty");

    T head = stack2.top();    //����ջ
    stack2.pop();             //ɾ��ջ��Ԫ��

    return head;
}



