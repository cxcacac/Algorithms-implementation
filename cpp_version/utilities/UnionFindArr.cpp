#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class DisjointSetUnion{
private:
    // unordered_map<int,int> also permitted
    vector<int> father, rank;
    int n;
public:
    DisjointSetUnion(int _n){
        n = _n;
        rank.resize(n, 1);
        father.resize(n);
        for (int i = 0; i < n; i++){
            father[i] = i;
        }
    }
    int find(int x){
        if(father[x]==x){
            return x;
        }
        else{
            int tmp = find(father[x]);
            father[x] = tmp;
            return tmp;
        }
    }

    void unionSet(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx==fy){
            return;
        }
        if(rank[fx] < rank[fy]){
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        father[fy] = fx;
    }

    int numberofConnectedComponent(){
        int num = 0;
        for (int i = 0; i < n; i++){
            if(father[i] == i){
                num++;
            }
        }
        return num;
    }
};

