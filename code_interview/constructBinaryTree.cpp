#include <stdexcept>

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode(int _val){
        m_nValue = _val;
        m_pLeft = nullptr;
        m_pRight = nullptr;
    }
    BinaryTreeNode():m_nValue(0),m_pLeft(nullptr),m_pRight(nullptr){}
};

// End include
BinaryTreeNode* constructHelper(int* preorderStart, int* preorderEnd, int* inorderStart, int* inorderEnd){
    int rootValue = preorderStart[0];
    BinaryTreeNode *root = new BinaryTreeNode(rootValue);
    if(preorderStart == preorderEnd){
        // 若只有一个元素，且值相同
        if(inorderEnd == inorderStart && *preorderStart == *inorderStart){
            return root;
        }
        else{
            throw std::exception("Invalid Input");
        }
    }
    int *tmp = inorderStart;
    while(tmp <= inorderEnd && *tmp != rootValue){
        ++tmp;
    }
    if(tmp>=inorderEnd && *tmp != rootValue){
        throw std::exception("Invalid Input");
    }
    int leftLength = tmp - inorderStart;
    int *leftPreorderEnd = preorderStart + leftLength;
    int *rightPreorderStart = leftPreorderEnd + 1;
    int *leftInorderEnd = tmp - 1;
    int *rightInorderStart = tmp + 1;
    if(leftLength > 0){
        root->m_pLeft = constructHelper(preorderStart, leftPreorderEnd, inorderStart, leftInorderEnd);
    }
    if(rightInorderStart <= inorderEnd){
        root->m_pRight = constructHelper(rightPreorderStart, preorderEnd, rightInorderStart, inorderEnd);
    }
    return root;
}


BinaryTreeNode* constructTree(int* preorder, int* inorder, int length){
    if (preorder == nullptr || inorder == nullptr||length <=0){
        return nullptr;
    }
    return constructHelper(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

