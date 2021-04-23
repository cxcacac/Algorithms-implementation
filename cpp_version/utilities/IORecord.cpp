/**
 * https://ac.nowcoder.com/acm/contest/5647
*/
// #include <iostream>
// #include <istream>　　　　
// #include <ostream>
// #include <sstream>　　　　
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <iterator>
// #include <queue>　　　　　
// #include <set>
// #include <stack>
// #include <map>

// we can use only one line to include all the headers
#include <bits/stdc++.h>

using namespace std;

int main(){
    return 0;
}

/*
 ***********************************************************************
 * for integers, using scanf or cin to read data till 
 * (1) scanf("%d", &num)==false, cin>>num==false, which can be judged by while.
 * (2) or cin>>size first, then use while(size--) to read 
 ***********************************************************************
*/
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
    // size0, 1, 2, 3
    // size1, 1, 2, 3
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
    // 1 2 3 4
    string input;
    while(getline(cin, input)){
        istringstream iss(input);
        int sum = 0, val;
        while(iss>>val){
            sum += val;
        }
        cout << sum << endl;
    }
}
/*
 ***********************************************************************
 * for strings, using getline(cin, output) to get each test case, return true if not null.
 * using istringstream to get each string into vector<string>.
 * istringstream read string like cin, use blank/tab/enter as end character.
 ***********************************************************************
*/
void stringIO(){
    // n
    // abc acd .... (n blanks) dfd
    // must not mix cin with getline
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
    // every input : every test case;
    string input;
    while(getline(cin, input)){
        istringstream iss(input);
        string s;
        vector<string> v;
        while(getline(iss, s, ',')){
            v.push_back(s);
        }
    }
}

