/**
 * LRU: Least recently used, if the data is used lately, it will be used in future.
 * Utilities: c++, doubly linked list.
 * Test Case:
 * LRUCache cache = new LRUCache(2);
 * cache.put(1, 1); -> null
 * cache.put(2, 2); -> null
 * cache.get(1); -> 1
 * cache.put(3, 3); ->null
 * cache.get(2);  -> -1
 * cache.put(1, 4); -> null
 * cache.get(1); -> 4
 * Tests:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
*/
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

struct DLinkedNode{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _val): key(_key), value(_val), prev(nullptr), next(nullptr) {}
};

class LRUcache{
private:
    int capacity;
    int cur_size;
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
public:
    LRUcache(int val): capacity(val), cur_size(0){
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(!cache.count(key)){
            return -1;
        }
        else{
            // move the node to the head;
            DLinkedNode *node = cache[key];
            moveToHead(node);
            return node->value;
        }
    }

    void put(int key, int value){
        DLinkedNode *cur = new DLinkedNode(key, value);
        if(!cache.count(key)){
            cur_size++;
            if(cur_size>capacity){
                DLinkedNode *removed =removeTail();
                cache.erase(removed->key);
                cur_size--;
                delete removed;
                removed = nullptr;
            }
            cache[key] = cur;
            addToHead(cur);
        }
        else{
            DLinkedNode *node = cache[key];
            node->value = value;
            removeNodeFromList(node);
            moveToHead(node);
        }
    }

    void removeNodeFromList(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode* node){
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }

    void moveToHead(DLinkedNode* node){
        removeNodeFromList(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){
        DLinkedNode *node = tail->prev;
        removeNodeFromList(node);
        return node;
    }
};

int main(){
    LRUcache *obj = new LRUcache(2);
    int value = 0;
    obj->put(1, 1);
    obj->put(2, 2);
    value = obj->get(1);
    cout << value << endl;
    obj->put(3, 3);
    value = obj->get(2);
    cout << value << endl;
    obj->put(1, 4);
    value = obj->get(1);
    cout << value << endl;
    return 0;
}
