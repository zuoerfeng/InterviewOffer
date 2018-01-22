#include <iostream>
#include <stack>
#include "List.h"
#include <cstdio>

using namespace std;

//采用迭代的方式，用栈中间存储节点
void PrintListReversingly_Iteratively(ListNode *pHead)
{
    //运用STL里面的栈作为存储节点，出栈即为反向输出
    stack<ListNode*> nodes;

    //进栈
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    //出栈
    while(!nodes.empty()){
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

//采用递归的方式，缺点是链表很大的时候，可能递归导致的调用栈会奔溃
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != nullptr)
    //if(pHead)
    {
        if(pHead->m_pNext != nullptr)
            PrintListReversingly_Recursively(pHead->m_pNext);    //非尾递归的做法会导致不停的创建新的调用栈
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

    //将这些节点按照链表的形式连接起来
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");
    ListNode* pNode1 = CreateListNode(1);
    Test(pNode1);
    DestroyList(pNode1);
}

// 空链表
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
