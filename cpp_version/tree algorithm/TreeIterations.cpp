#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct binaryTree{
    int val;
    binaryTree *left;
    binaryTree *right;
    binaryTree(int _val):val(_val),left(nullptr),right(nullptr){}
};

void inorderTraversal(binaryTree* root){
    binaryTree *cur = root;
    stack<binaryTree*> s;
    vector<int> res;
    while(cur||!s.empty()){
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        binaryTree *node = s.top();
        s.pop();
        res.push_back(node->val);
        cur = node->right;
    }
    for(auto val: res){
        cout << val << ' ';
    }
}

int main(){

}
