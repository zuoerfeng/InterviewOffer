//赋值运算符函数的定义
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

//类的声明
class CMyString;

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();

private:
    char* m_pData;
};

CMyString::CMyString(char *pData)
{
    if(pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

//普通的写法：
//1.判断是否为自身的赋值，2.释放原本空间，3.创建一个新的空间
//问题：delete失败则会抛出异常，这个时候原本对象也会无法保留
/*
CMyString& CMyString:: operator = (const CMyString& str){
    if(&str == this)
        return *this;

    delete[] m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
*/

//高级的写法：
//利用临时变量，做赋值的交换
CMyString& CMyString:: operator = (const CMyString& str){
    if(&str != this){
        CMyString tmp(str);
        char* str_tmp = tmp.m_pData;
        tmp.m_pData = m_pData;
        m_pData = str_tmp;    //离开if tmp自动被析构，m_pData原本的值恰好被释放掉，即使发生异常，也不会影响到新的m_pData
    }

    return *this;
}


// ====================测试代码====================
void CMyString::Print(){
    printf("%s",m_pData);
}
