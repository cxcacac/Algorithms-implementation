#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// test case format: a b
// 1 7
// 1 3
// 1 6
// 1 2

int main(){
    // if the remainer ever exist, then it must be a infinite decimal;
    int a, b;
    cin>>a>>b;
    string res;
    unordered_map<int, int> mp;
    int div = a / b;
    int re = a % b;
    res += to_string(div);
    if(re==0){
        cout << res << endl;
        return 0;
    }
    res += ".";
    int index = res.size()-1;
    int cnt = index;
    while(re!=0){
        cnt++;
        // if remainder exists;
        div = re*10 / b;
        if(mp.count(re)){
            int l = mp[re];
            res = res.substr(0, l) + "(" + res.substr(l) + ")";
            cout << res << endl;
            return 0;
        }
        res.push_back(div + '0');
        mp[re] = cnt;
        re = re*10 % b;
    }
    cout << res << endl;
}

