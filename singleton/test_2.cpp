#include <iostream>
#include <mutex>     //互斥锁的头文件
#include <thread>    //多线程的头文件
#include <vector>
using namespace std;

class Singleton
{

public:
    static Singleton* getInstance(){
        if(m_pInstance == NULL){
            m_mutex.lock();                         // 使用C++11中的多线程库（给当前线程加锁）
            if(m_pInstance == NULL){                // 两次判断是否为NULL的双重检查
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
    static mutex m_mutex;  // 互斥量

    Singleton(){}
    static Singleton* m_pInstance;
};

Singleton* Singleton::m_pInstance = NULL;
mutex Singleton::m_mutex;

//获得该线程的一个实例，并打印该实例的地址
void print_singleton_instance(){
    Singleton *singletonObj = Singleton::getInstance();
    cout << singletonObj << endl;
}

// 多个进程获得单例
void Test1(){
    // 预期结果，打印出相同的地址，之间可能缺失换行符，也属正常现象
    vector<thread> threads;
    for(int i = 0; i < 10; ++i){
        threads.push_back(thread(print_singleton_instance));     //thread()是创建一个线程的意思，
    }

    for(auto& thr : threads){
        thr.join();                                              //thr.join阻塞当前主进程，等待所有线程执行完成
    }
}

int main(){
    Test1();
    Singleton::destroyInstance();
    return 0;
}
