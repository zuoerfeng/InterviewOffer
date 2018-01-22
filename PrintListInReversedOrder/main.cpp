#include <iostream>
#include <stack>
#include "List.h"
#include <cstdio>

using namespace std;

//���õ����ķ�ʽ����ջ�м�洢�ڵ�
void PrintListReversingly_Iteratively(ListNode *pHead)
{
    //����STL�����ջ��Ϊ�洢�ڵ㣬��ջ��Ϊ�������
    stack<ListNode*> nodes;

    //��ջ
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    //��ջ
    while(!nodes.empty()){
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

//���õݹ�ķ�ʽ��ȱ��������ܴ��ʱ�򣬿��ܵݹ鵼�µĵ���ջ�ᱼ��
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != nullptr)
    //if(pHead)
    {
        if(pHead->m_pNext != nullptr)
            PrintListReversingly_Recursively(pHead->m_pNext);    //��β�ݹ�������ᵼ�²�ͣ�Ĵ����µĵ���ջ
        printf("%d\t", pHead->m_nValue);
    }

}

void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    //����Щ�ڵ㰴���������ʽ��������
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// ֻ��һ����������: 1
void Test2()
{
    printf("\nTest2 begins.\n");
    ListNode* pNode1 = CreateListNode(1);
    Test(pNode1);
    DestroyList(pNode1);
}

// ������
void Test3()
{
    printf("\nTest3 begins.\n");
    Test(nullptr);
}

int main()
{
    cout << "Hello world!" << endl;
    Test1();
    Test2();
    Test3();
    return 0;
}
