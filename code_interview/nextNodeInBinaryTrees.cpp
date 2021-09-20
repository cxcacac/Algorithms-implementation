#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode *parent;
    BinaryTreeNode(){
        val = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    BinaryTreeNode(int _val){
        val = _val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

BinaryTreeNode* getNextNode(BinaryTreeNode* pNode){
    if(pNode==nullptr){
        return nullptr;
    }
    if(pNode->right != nullptr){
        BinaryTreeNode *cur = pNode->right;
        while(cur->left){
            cur = cur->left;
        }
        return cur;
    }
    else if(pNode->parent != nullptr){
        BinaryTreeNode *cur = pNode;
        while(cur->parent != nullptr && cur->parent->left != cur){
            cur = cur->parent;
        }
        return cur->parent;
    }
    return nullptr;
}
