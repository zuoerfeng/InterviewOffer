#include <iostream>

using namespace std;

class test_null{
};

class test{
public:
    test() = default;
    ~test(){}
    int a(){return 0;}
};

class test_1{
public:
    test_1() = default;
    virtual void b() const {}
    ~test_1(){}
};

class test_2 : public test_1{
};

class test_3 : public test{

public:
    //test_3(test_3 tmp)
    test_3(const test_3 &tmp){
        a = tmp.a;}
private : int a;
};

int main()
{
    cout << "Hello world!" << endl;

    test_null a;
    test b;
    test_1 c;
    test_2 d;
    cout << sizeof(a) << endl;    //���1����������ʵ����һ�����࣬������Ϊ��������������ڴ��д���е�ַ����������1���ֽڡ�
    cout << sizeof(b) << endl;    //���1���������ڹ������������������ֻ��Ҫ��������Ӧ�ĺ�����ַ���������ַֻ�������йأ��Ͷ�����û�й�ϵ�ģ����Բ�����Ӱ�����Ĵ�С
    cout << sizeof(c) << endl;    //���4����Ϊ�麯������һ���麯�������������Զ�����Ϊ����������һ��ָ���麯�����ָ�룬���ָ���sizeof��Сȡ���ڻ����ĵ�ַ�ռ��С
    cout << sizeof(d) << endl;    //���4����Ϊ�̳еĸ�������һ���麯������������Ҳ�����麯�������Ҳ���ж�Ӧָ���麯�����ָ��

    return 0;
}
