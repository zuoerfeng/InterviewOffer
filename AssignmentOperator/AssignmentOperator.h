//��ֵ����������Ķ���
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

//�������
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

//��ͨ��д����
//1.�ж��Ƿ�Ϊ����ĸ�ֵ��2.�ͷ�ԭ���ռ䣬3.����һ���µĿռ�
//���⣺deleteʧ������׳��쳣�����ʱ��ԭ������Ҳ���޷�����
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

//�߼���д����
//������ʱ����������ֵ�Ľ���
CMyString& CMyString:: operator = (const CMyString& str){
    if(&str != this){
        CMyString tmp(str);
        char* str_tmp = tmp.m_pData;
        tmp.m_pData = m_pData;
        m_pData = str_tmp;    //�뿪if tmp�Զ���������m_pDataԭ����ֵǡ�ñ��ͷŵ�����ʹ�����쳣��Ҳ����Ӱ�쵽�µ�m_pData
    }

    return *this;
}


// ====================���Դ���====================
void CMyString::Print(){
    printf("%s",m_pData);
}
