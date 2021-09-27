#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int _val) : val(_val), next(nullptr){}
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
    if(!pListHead||!pToBeDeleted){
        return;
    }
    if(pToBeDeleted->next != nullptr){
        ListNode *pNext = pToBeDeleted->next;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->next = pNext->next;
        delete pNext;
        pNext = nullptr;
    }
    else if(pToBeDeleted == *pListHead){
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    else{
        ListNode *pNode = *pListHead;
        while(pNode->next != pToBeDeleted){
            pNode = pNode->next;
        }
        delete pToBeDeleted;
        pNode->next = nullptr;
        pToBeDeleted = nullptr;
    }
}
