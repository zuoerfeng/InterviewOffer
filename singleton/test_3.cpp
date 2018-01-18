#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class Singleton
{

public:
    static Singleton* getInstance(){

        return const_cast<Singleton *>(m_pInstance); // ȥ����const������
        // ע�⣡���ú����ķ���ֵ��Ϊconst static�ͣ���˴����ؽ���const_cast��̬ת��
        // ���Ըú������Ը�Ϊ��
        /*
        const static Singleton* getInstance(){
            return m_pInstance;
        }
        */
    }

    static void destroyInstance(){
        if(m_pInstance != NULL){
            delete m_pInstance;
            m_pInstance = NULL;
        }
    }

private:
    Singleton(){}
    static const Singleton* m_pInstance;
};

const Singleton* Singleton::m_pInstance = new Singleton(); // ����constֻ�ܶ���һ�Σ������ٴ��޸ĵ����ԣ�static������������ֻ��һ��ʵ��

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

int main(){
    Test1();
    Singleton::destroyInstance();
    return 0;
}
