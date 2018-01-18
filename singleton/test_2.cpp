#include <iostream>
#include <mutex>     //��������ͷ�ļ�
#include <thread>    //���̵߳�ͷ�ļ�
#include <vector>
using namespace std;

class Singleton
{

public:
    static Singleton* getInstance(){
        if(m_pInstance == NULL){
            m_mutex.lock();                         // ʹ��C++11�еĶ��߳̿⣨����ǰ�̼߳�����
            if(m_pInstance == NULL){                // �����ж��Ƿ�ΪNULL��˫�ؼ��
                m_pInstance = new Singleton();
            }
            m_mutex.unlock();
        }
        return m_pInstance;
    }

    static void destroyInstance(){
        if(m_pInstance != NULL){
            delete m_pInstance;
            m_pInstance = NULL;
        }
    }


private:
    static mutex m_mutex;  // ������

    Singleton(){}
    static Singleton* m_pInstance;
};

Singleton* Singleton::m_pInstance = NULL;
mutex Singleton::m_mutex;

//��ø��̵߳�һ��ʵ��������ӡ��ʵ���ĵ�ַ
void print_singleton_instance(){
    Singleton *singletonObj = Singleton::getInstance();
    cout << singletonObj << endl;
}

// ������̻�õ���
void Test1(){
    // Ԥ�ڽ������ӡ����ͬ�ĵ�ַ��֮�����ȱʧ���з���Ҳ����������
    vector<thread> threads;
    for(int i = 0; i < 10; ++i){
        threads.push_back(thread(print_singleton_instance));     //thread()�Ǵ���һ���̵߳���˼��
    }

    for(auto& thr : threads){
        thr.join();                                              //thr.join������ǰ�����̣��ȴ������߳�ִ�����
    }
}

int main(){
    Test1();
    Singleton::destroyInstance();
    return 0;
}
