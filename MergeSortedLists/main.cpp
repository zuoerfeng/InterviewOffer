#include <iostream>
#include <cstdio>
#include "List.h"

using namespace std;

/*
//ȡ��������������С�Ľڵ㣨�ݹ�ķ�����
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    //��ĳһ������Ϊ�յ�ʱ������һ��ʣ�����������ֱ�ӷ��ںϲ�����ĺ�����
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

//ȡ��������������С�Ľڵ㣨ѭ���ķ�����
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    //��ĳһ������Ϊ�յ�ʱ������һ��ʣ�����������ֱ�ӷ��ںϲ�����ĺ�����
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;

    ListNode* pMergedHead = nullptr;
    ListNode* pnode = nullptr;

    //����ѡȡһ��ͷ���
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

    //Ȼ����кϲ�
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

// ====================���Դ���====================
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

// �������������ظ�������
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

// ��������ֻ��һ������
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// һ������Ϊ������
// list1: 1->3->5
// list2: ������
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

// ��������Ϊ������
// list1: ������
// list2: ������
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
