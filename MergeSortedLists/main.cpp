#include <iostream>
#include <cstdio>
#include "List.h"

using namespace std;

/*
//取出两个链表中最小的节点（递归的方法）
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    //当某一个链表为空的时候，另外一个剩余的链表即可以直接放在合并链表的后面了
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;

    ListNode* pMergedHead = nullptr;
    if(pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge(pHead1->m_pNext,pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge(pHead1,pHead2->m_pNext);
    }
    return pMergedHead;
}
*/

//取出两个链表中最小的节点（循环的方法）
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    //当某一个链表为空的时候，另外一个剩余的链表即可以直接放在合并链表的后面了
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;

    ListNode* pMergedHead = nullptr;
    ListNode* pnode = nullptr;

    //首先选取一个头结点
    if(pHead1->m_nValue <= pHead2->m_nValue){
        pMergedHead = pHead1;
        pnode = pMergedHead;
        pHead1 = pHead1->m_pNext;
    }
    else{
        pMergedHead = pHead2;
        pnode = pMergedHead;
        pHead1 = pHead2->m_pNext;
    }

    //然后进行合并
    while(pHead1 != nullptr && pHead2 != nullptr){
        if(pHead1->m_nValue <= pHead2->m_nValue){
            pnode->m_pNext = pHead1;
            pHead1 = pHead1->m_pNext;
        }
        else{
            pnode->m_pNext = pHead2;
            pHead2 = pHead2->m_pNext;
        }
        pnode = pnode->m_pNext;
    }

    while(pHead1 != nullptr){
        pnode->m_pNext = pHead1;
        pHead1 = pHead1->m_pNext;
        pnode = pnode->m_pNext;
    }

    while(pHead2 != nullptr){
        pnode->m_pNext = pHead2;
        pHead2 = pHead2->m_pNext;
        pnode = pnode->m_pNext;
    }

    return pMergedHead;
}

// ====================测试代码====================
ListNode* Test(char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, NULL);

    DestroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = Test("Test5", NULL, NULL);
}

int main()
{
    cout << "Hello world!" << endl;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
