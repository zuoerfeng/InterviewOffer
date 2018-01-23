#include <iostream>
#include "BinaryTree.h"
#include <cstdio>
#include <exception>   //�쳣�����������ͷ�ļ�
#include <stdexcept>

using namespace std;

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

//����������������Ϊǰ������������
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length < 0)
        return nullptr;

    //�������������������ʼ���й������Ĳ���
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);

}

//����ǰ�����У��ж�����������������������
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    //�����ڵ���ҽڵ�ָ����ͬһ���ڵ㣬��������ͬ����ʾ��ǰ�ݹ鵽Ҷ�ӽڵ��ˡ�
    if(startPreorder == endPreorder){
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw runtime_error("Invalid input.");
    }

    //������������ҵ����ڵ㣬���ڵ��������Ϊ���������ұ�����Ϊ������
    int* rootInoder = startInorder;
    while(rootInoder <= endInorder && *rootInoder != rootValue){
        ++ rootInoder;
    }

    if(rootInoder == endInorder && *rootInoder != rootValue)
        throw runtime_error("Invalid input.");

    int leftLength = rootInoder - startInorder;    //���ݸ��ڵ��ж����������и���
    int* leftPreorderEnd = startPreorder + leftLength;      //��ǰ���м����������ĸ�

    if(leftLength >0){
        //����������
        root->m_pLeft = ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInoder-1);
    }
    if(leftLength < endPreorder - startPreorder){
        // ����������
        root->m_pRight = ConstructCore(leftPreorderEnd+1,endPreorder,rootInoder+1,endInorder);
    }

    return root;
}

// ====================���Դ���====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    //�쳣����ģ��
    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(runtime_error)
    {
        printf("Invalid Input.\n");
    }
}

// ��ͨ������
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//           /
//          2
//         /
//        3
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//             \
//              2
//               \
//                3
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// ����ֻ��һ�����
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// �����ָ��
void Test6()
{
    Test("Test6", NULL, NULL, 0);
}

// ������������в�ƥ��
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
}


int main()
{
    cout << "Hello world!" << endl;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
