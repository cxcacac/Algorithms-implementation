#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class HashSetListVersion{
private:
    vector<list<int>> data;
    static const int base = 1007;
    static int hash(int key){
        return key % base;
    }
public:
    HashSetListVersion() : data(base){}
    void add(int key){
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++){
            if(*it==key){
                return;
            }
        }
        data[h].push_back(key);
    }

    void remove(int key){
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++){
            if(*it == key){
                data[h].erase(it);
                return ;
            }
        }
    }

    bool contains(int key){
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++){
            if(*it==key){
                return true;
            }
        }
        return false;
    }
};
