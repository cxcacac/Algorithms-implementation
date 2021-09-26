// #include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

char* getMemory(){
    char p[] = "Hello world";
    return p;
}

int main(){
    char* p = getMemory();
    cout << p << endl;
}
