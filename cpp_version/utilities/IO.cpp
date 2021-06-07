// https://ac.nowcoder.com/acm/contest/5647

#include <iostream>
#include <istream>　　　　
#include <ostream>
#include <sstream>　　　　
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include <queue>　　　　　
#include <set>
#include <stack>
#include <map> 
// use #include <bits/stdc++.h> 

using namespace std;

int main(){
    return 0;
}

void integerIO(){
    // input: a b
    // output: a+b
    int a, b;
    while(scanf("%d %d", &a, &b)){
        printf("%d\n", a + b);
    }
    while(cin>>a>>b){
        cout << a + b << endl;
    }

    // size
    // 1, 2, 3
    int t;
    int a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    // end with a=0,b=0
    int a, b;
    while(scanf("%d %d", &a, &b) && a!=0 && b!=0){
        printf("%d\n", a + b);
    }

    // size, 1, 2, 3
    // size, 1, 2, 3
    int num;
    while(scanf("%d", &num)!=EOF){
        int val = 0;
        int cur;
        for (int i = 0; i < num; i++){
            scanf("%d", &cur);
            val += cur;
        }
        printf("%d\n", val);
    }

    // 1 2 3 4
    // 1 2 3 4 5
    // 1 2 3
    string input;
    while(getline(cin, input)){
        istringstream iss(input);
        int sum = 0, val;
        while(iss>>val){
            sum += val;
        }
        cout << sum << endl;
    }

    // two long type interger
    long a, b;
    long c;
    while(scanf("%ld %ld", &a, &b)!=EOF){
        c = a+b;
        printf("%ld\n", c);
    }
}
void stringIO(){
    // size = n
    // abc acd .... dfd
    // abc acd .... dfd
    int num;
    cin >> num;
    vector<string> v;
    string val;
    while(num--){
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    unsigned long len = v.size();
    for (int i = 0; i < len; i++){
        cout << v[i] << ' ';
    }
    cout << v.back()<<endl;

    // abc adc dfa dfa dfdf
    // abs dfd sdf ass ass
    string input;
    while(getline(cin, input)){
        istringstream iss(input);
        string s;
        vector<string> v;
        while(iss>>s){
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        unsigned long len = v.size();
        for (int i = 0; i < len - 1; i++){
            cout << v[i] << ' ';
        }
        cout << v.back() << endl;
    }

    // abc,add,bcd,add
    // abd,add,add,add,add
    string input;
    while(getline(cin, input)){
        istringstream iss(input);
        string s;
        vector<string> v;
        while(getline(iss, s, ',')){
            v.push_back(s);
        }
    }

    // mixed input
    // abcd, 32, 123, abdc
    string input;
    vector<string> v;
    cin >> input;
    istringstream iss(input);
    string substr;
    while(getline(iss, substr, ',')){
        v.push_back(substr);
    }
}

