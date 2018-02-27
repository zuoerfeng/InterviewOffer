#include <iostream>
#include <cstdio>
#include "List.h"

using namespace std;

//反转链表，为了防止链表断裂，需要有三个指针
ListNode* ReverseList(ListNode* pHead)
{
    //定义三个指针，分别指向节点的前中后
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;

    while(pNode != nullptr){
        ListNode* pNext = pNode->m_pNext;

        if(pNext == nullptr)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(NULL);
}

int main()
{
    cout << "Hello world!" << endl;
    Test1();
    Test2();
    Test3();
    return 0;
}
