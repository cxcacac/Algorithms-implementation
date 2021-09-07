#include<vector>
#include<iostream>

using namespace std;

class MyQueue{
private:
    vector<int> arr;
    int size;
    int l = 0;
    int r = 0;

public:
    MyQueue(int n): size(n){
        arr.resize(n, 0);
    }
    void push(int val){
        if(r+1==l){
            cout << "error" << endl;
            return;
        }
        r++;
        arr[r % size] = val;
    }
    int top(){
        return arr[l];
    }
    void pop(){
        arr[l] = 0;
        l++;
    }
};
