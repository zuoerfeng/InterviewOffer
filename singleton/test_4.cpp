#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class Singleton
{
public:
    static Singleton* getInstance(){
        static Singleton m_pInstance; // ע�⣬�����ڸú�����,ע�����������Ķ�����һ������̬�Ķ���ֻ��һ��
        return &m_pInstance;
    }

private:
    Singleton(){}
};

void print_singleton_instance(){
    Singleton *singletonObj = Singleton::getInstance();
    cout << singletonObj << endl;
}

// ������̻�õ���
void Test1(){
    // Ԥ�ڽ������ӡ����ͬ�ĵ�ַ��֮�����ȱʧ���з���Ҳ����������
    vector<thread> threads;
    for(int i = 0; i < 10; ++i){
        threads.push_back(thread(print_singleton_instance));
    }

    for(auto& thr : threads){
        thr.join();
    }
}

// �������̻�ö��ʵ��
void Test2(){
    // Ԥ�ڽ������ӡ����ͬ�ĵ�ַ��֮�任�з��ָ�
    print_singleton_instance();
    print_singleton_instance();
}

int main(){
    cout << "Test1 begins: " << endl;
    Test1();
    cout << "Test2 begins: " << endl;
    Test2();
    return 0;
}
