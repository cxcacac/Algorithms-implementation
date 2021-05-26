#include <string>
#include <vector>
#include <iostream>

using namespace std;

void getNext(string &p, vector<int> &next);
void printArray(vector<int> &a, int i, int j);
int matchStrings(const string &s, const string &p, vector<int> &next);

int main(){
    string s = "abcddabsss", p = "abc";
    int n = p.size();
    vector<int> next(n);
    getNext(p, next);
    printArray(next, 0, n);
    int startIndex = matchStrings(s, p, next);
    cout <<"Matching starting from:"<<startIndex << endl;
    return 0;
}


void getNext(string& p, vector<int>& next){
    int n = p.size();
    int k = -1;
    int j = 0;
    next[0] = -1;
    while(j<n-1){
        if(k==-1||p[j]==p[k]){
            j++;
            k++;
            if(p[j]!=p[k]){
                next[j] = k;
            }
            else{
                next[j] = next[k];
            }
        }
        else{
            k = next[k];
        }
    }
}

int matchStrings(const string &s, const string &p, vector<int>& next){
    int m = s.size();
    int n = p.size();
    int i = 0, j = 0;
    while(i<m && j<n){
        if(s[i]==p[j] || next[j]==-1){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if(j==n){
        return i - j;
    }
    return -1;
}

void printArray(vector<int>& a, int i, int j){
    for (int k = i; k < j; k++){
        cout << a[k] << " ";
    }
}

