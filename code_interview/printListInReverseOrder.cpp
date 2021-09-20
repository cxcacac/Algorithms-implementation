// TODO
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(){
        val = 0;
        next = nullptr;
    };
    ListNode(int _val){
        val = _val;
        next = nullptr;
    }
};

ListNode* createList(const vector<int> & nums){
    if(nums.empty()){
        return nullptr;
    }
    int n = nums.size();
    ListNode *head = new ListNode(nums[0]);
    ListNode *p = head;
    for (int i = 1; i < n; i++){
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

void printListReversely_Iteratively(ListNode* pHead){
    stack<ListNode *> nodes;
    while(pHead != nullptr){
        nodes.push(pHead);
        pHead = pHead->next;
    }
    while(!nodes.empty()){
        ListNode *pNode = nodes.top();
        printf("%d\t", pNode->val);
        nodes.pop();
    }
}

void printListReversely_Recursively(ListNode* pHead){
    if(pHead != nullptr){
        printListReversely_Iteratively(pHead->next);
        printf("%d\t", pHead->val);
    }
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = createList(nums);
    printListReversely_Iteratively(head);
    printf("\n");
    printListReversely_Recursively(head);
}
