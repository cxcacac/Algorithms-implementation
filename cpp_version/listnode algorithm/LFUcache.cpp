//Reference https://leetcode-cn.com/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <list>

using namespace std;

// Set version not work yet

// struct NodeSetVersion {
//     int cnt, time, key, value;

//     NodeSetVersion(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}

//     bool operator < (const NodeSetVersion& rhs) const {
//         return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
//     }
// };


// // set是有序的
// class LFUcacheSetVersion{
// private:
//     int capacity, time;
//     unordered_map<int, NodeSetVersion> keyMap;
//     set<NodeSetVersion> nodeSet;
// public:
//     LFUcacheSetVersion(int _capacity){
//         capacity = _capacity;
//         time = 0;
//         keyMap.clear();
//         nodeSet.clear();
//     }
//     int get(int key){
//         if(capacity == 0)
//             return -1;
//         if(!keyMap.count(key)){
//             return -1;
//         }
//         NodeSetVersion cache = keyMap[key];
//         nodeSet.erase(cache);
//         cache.cnt++;
//         cache.time = ++time;
//         nodeSet.insert(cache);
//         keyMap[key] = cache;
//         return cache.value;
//     }
//     void put(int key, int value){
//         if(capacity == 0)
//             return;
//         if(keyMap.find(key) == keyMap.end()){
//             if((int)keyMap.size() == capacity){
//                 keyMap.erase(nodeSet.begin()->key);
//                 nodeSet.erase(nodeSet.begin());
//             }
//             NodeSetVersion cache = NodeSetVersion(1, ++time, key, value);
//             // 添加进来的时候，是对临时变量加了拷贝复制
//             keyMap.insert(make_pair(key,cache));
//             nodeSet.insert(cache);
//         }
//         else{
//             // 和get函数相同，但要修改值
//             NodeSetVersion cache = keyMap[key];
//             nodeSet.erase(cache);
//             cache.time = ++time;
//             cache.cnt++;
//             cache.value = value;
//             nodeSet.insert(cache);
//             keyMap[key] = cache;
//         }
//     }
// };

struct Node{
    int val, key, cnt;
    Node(int _val, int _key, int _cnt): val(_val), key(_key), cnt(_cnt){}
};

class LFUcacheDoubleHashVersion{
private:
    int capacity, minfreq;
    unordered_map<int, list<Node>::iterator> keyMap;
    unordered_map<int, list<Node>> freqMap;
public:
    LFUcacheDoubleHashVersion(int _capacity){
        capacity = _capacity;
        minfreq = 0;
        keyMap.clear();
        freqMap.clear();
    }
    int get(int key){
        if(capacity==0)
            return -1;
        if(!keyMap.count(key)){
            return -1;
        }
        list<Node>::iterator node = keyMap[key];
        int value = node->val, freq = node->cnt;
        // 删去node，加到下一层，省去双向链表的连接过程
        freqMap[freq].erase(node);
        // 优化最小的freq值
        if(freqMap[freq].size() == 0){
            freqMap.erase(freq);
            if(minfreq == freq)
                minfreq ++;
        }
        freqMap[freq + 1].push_front(Node(value + 1, key, freq + 1));
        keyMap[key] = freqMap[freq + 1].begin();
        return value;
    }
    void put(int key, int value){
        if(capacity==0)
            return ;
        if(keyMap.count(key)){
            list<Node>::iterator node = keyMap[key];
            int freq = node->cnt;
            freqMap[freq].erase(node);
            if(freqMap[freq].size() == 0){
                // 移除对应键
                freqMap.erase(freq);
                if(minfreq==freq)
                    minfreq++;
            }
            freqMap[freq + 1].push_front(Node(value, key, freq + 1));
            keyMap[key] = freqMap[freq + 1].begin();
        }
        else{
            if(capacity==(int)keyMap.size()){
                // 删除list的最后一个
                // 最后是一个struct
                auto node = freqMap[minfreq].back();
                int key = node.key;
                keyMap.erase(key);
                freqMap[minfreq].pop_back();
                if(freqMap[minfreq].size()==0){
                    freqMap.erase(minfreq);
                }
            }
            // 所有元素的频次都是从1开始累加
            freqMap[1].push_front(Node(value, key, 1));
            keyMap[key] = freqMap[1].begin();
            minfreq = 1;
        }
    }
};

int main(){
    // error
    LFUcacheDoubleHashVersion tmp = LFUcacheDoubleHashVersion(3);
    tmp.put(1, 2);
    cout << tmp.get(1) << endl;
    tmp.put(1, 3);
    cout << tmp.get(1) << endl;
    tmp.put(2, 3);
    tmp.put(5, 6);
    tmp.put(8, 9);
    cout << tmp.get(2) << endl;
}
