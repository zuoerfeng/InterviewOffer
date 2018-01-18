#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class Singleton
{

public:
    static Singleton* getInstance(){

        return const_cast<Singleton *>(m_pInstance); // 去掉“const”特性
        // 注意！若该函数的返回值改为const static型，则此处不必进行const_cast静态转换
        // 所以该函数可以改为：
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

const Singleton* Singleton::m_pInstance = new Singleton(); // 利用const只能定义一次，不能再次修改的特性，static继续保持类内只有一个实例

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

int main(){
    Test1();
    Singleton::destroyInstance();
    return 0;
}
