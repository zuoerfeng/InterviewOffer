#include <stack>
#include <exception>
#include <stdexcept>

using namespace std;

//建立一个模板类，使用的是两个栈实现一个队列
template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    //在队列末尾添加一个元素
    void appendTail(const T& node);

    //在队列队头删除一个元素
    T& deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

//模板类的定义和声明都得在同一个头文件里面
template <typename T>
CQueue<T>::CQueue(void){}

template <typename T>
CQueue<T>::~CQueue(void){}

template <typename T>     //注意模板类的函数定义，必须如此，返回值必须带有，否则无法匹配到类里面的函数声明
void CQueue<T>::appendTail(const T& node){
    stack1.push(node);
}

template <typename T>
T& CQueue<T>::deleteHead(){
    //判断stack是不是为空，不为空，将stack1的数据移动到stack2
    if(stack2.size() <= 0)
    {
        while(stack1.size()>0){         //移动stack1的所有数据
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0)
        throw runtime_error("queue is empty");

    T head = stack2.top();    //弹出栈
    stack2.pop();             //删除栈顶元素

    return head;
}



