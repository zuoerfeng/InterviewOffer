#include <iostream>
#include "List.h"
#include <stdexcept>
#include <cstdio>

using namespace std;

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted){
        throw runtime_error("the delete node is null");
        return;
    }

    // 要删除的结点不是尾结点，后一节点覆盖前一节点删除
    if(pToBeDeleted->m_pNext != nullptr){
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = nullptr;
    }
    else if(*pListHead == pToBeDeleted){         //要删除的是头结点
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    else    //要删除的是尾节点
    {
        ListNode* pNode = *pListHead;
        //遍历链表，得到尾节点的前一个节点
        while(pNode->m_pNext != pToBeDeleted){
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);

    printf("The result list is: \n");
    PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
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

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
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

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
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

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test(NULL, NULL);
}


int main()
{
    cout << "Hello world!" << endl;

    cout << "Test1" << endl;
    Test1();

    cout << "Test2" << endl;
    Test2();

    cout << "Test2" << endl;
    Test3();

    cout << "Test4" << endl;
    Test4();

    cout << "Test5" << endl;
    Test5();

    return 0;
}
