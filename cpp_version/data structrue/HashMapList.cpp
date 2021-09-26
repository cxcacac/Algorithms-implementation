#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class HashMapListVersion{
private:
    vector<list<pair<int, int>>> data;
    static const int base = 1007;
    static int hash(int key){
        return key % base;
    }
public:
    // initialization
    HashMapListVersion():data(base){}

    void put(int key, int value){
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++){
            if(it->first == key){
                it->second = value;
                return;
            }
        }
        // save original values;
        data[h].push_back(make_pair(key, value));
    }

    int get(int key){
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++){
            if(it->first == key){
                return it->second;
            }
        }
        // exceptions
        return -1;
    }

    void remove(int key){
        // no exceptions
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++){
            if(it->first == key){
                data[h].erase(it);
                return ;
            }
        }
    }
};


int main(){
    HashMapListVersion mymap = HashMapListVersion();
    mymap.put(1, 2);
    mymap.put(3, 4);
    cout << mymap.get(1) << endl;
    cout << mymap.get(3) << endl;
    mymap.put(3, 2);
    cout << mymap.get(3) << endl;
}
