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
    cout << sizeof(a) << endl;    //输出1，这是由于实例化一个空类，编译器为了让这个对象再内存中存放有地址，主动加了1个字节。
    cout << sizeof(b) << endl;    //输出1，这是由于构造和析构函数编译器只需要给其分配对应的函数地址，而这个地址只和类型有关，和对象是没有关系的，所以并不会影响对象的大小
    cout << sizeof(c) << endl;    //输出4，因为虚函数会有一个虚函数表，编译器会自动产生为这个对象产生一个指向虚函数表的指针，这个指针的sizeof大小取决于机器的地址空间大小
    cout << sizeof(d) << endl;    //输出4，因为继承的父类是有一个虚函数，则子类中也会有虚函数，因此也会有对应指向虚函数表的指针

    return 0;
}
