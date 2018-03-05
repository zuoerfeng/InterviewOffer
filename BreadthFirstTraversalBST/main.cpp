#include <iostream>
#include <deque>
#include "BinaryTree.h"
using namespace std;

//广度优先遍历，利用的是队列，根节点先进队列，之后的子节点在进入队列
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
    if(!pTreeRoot)
        return;

    //申请一个双端队列，利用STL
    deque<BinaryTreeNode *> dequeTreeNode;

    //首先加入根节点
    dequeTreeNode.push_back(pTreeRoot);

    while(dequeTreeNode.size()){
        BinaryTreeNode* node = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        cout << node->m_nValue << endl;

        if(node->m_pLeft)
            dequeTreeNode.push_back(node->m_pLeft);
        if(node->m_pRight)
            dequeTreeNode.push_back(node->m_pRight);
    }
}

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    PrintTree(pNode8);

    cout << "=====Test1: PrintFromTopToBottom=====\n"<< endl;
    PrintFromTopToBottom(pNode8);

    DestroyTree(pNode8);
}

int main()
{
    cout << "Hello world!" << endl;

    Test1();

    return 0;
}
