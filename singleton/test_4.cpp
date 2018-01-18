#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class Singleton
{
public:
    static Singleton* getInstance(){
        static Singleton m_pInstance; // 注意，声明在该函数内,注意这里声明的对象是一个，静态的对象只有一个
        return &m_pInstance;
    }

private:
    Singleton(){}
};

void print_singleton_instance(){
    Singleton *singletonObj = Singleton::getInstance();
    cout << singletonObj << endl;
}

// 多个进程获得单例
void Test1(){
    // 预期结果，打印出相同的地址，之间可能缺失换行符，也属正常现象
    vector<thread> threads;
    for(int i = 0; i < 10; ++i){
        threads.push_back(thread(print_singleton_instance));
    }

    for(auto& thr : threads){
        thr.join();
    }
}

// 单个进程获得多次实例
void Test2(){
    // 预期结果，打印出相同的地址，之间换行符分隔
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
