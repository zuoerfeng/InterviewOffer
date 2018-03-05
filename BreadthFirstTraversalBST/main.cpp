#include <iostream>
#include <deque>
#include "BinaryTree.h"
using namespace std;

//������ȱ��������õ��Ƕ��У����ڵ��Ƚ����У�֮����ӽڵ��ڽ������
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
    if(!pTreeRoot)
        return;

    //����һ��˫�˶��У�����STL
    deque<BinaryTreeNode *> dequeTreeNode;

    //���ȼ�����ڵ�
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

// ====================���Դ���====================
// ������ȫ������������Ҷ�ӽڵ㣬�����ڵ㶼�������ӽڵ�
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
