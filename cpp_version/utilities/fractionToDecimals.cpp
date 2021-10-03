#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator){
    string res;
    unordered_map<long long, int> mp;
    // use long long to avoid integer overflow issues
    long long lnum = numerator, lde = denominator;
    // for -0.5
    if((lnum<0&&lde>0)||(lnum>0&&lde<0)){
        res += '-';
    }
    res += to_string(abs(lnum) / abs(lde));
    if(lnum%lde==0){
        return res;
    }
    res += '.';
    int idx = res.size();
    lnum %= lde;
    while(lnum != 0){
        if(mp.count(lnum)){
            int loc = mp[lnum];
            res = res.substr(0, loc) + '(' + res.substr(loc) + ')';
            return res;
        }
        mp[lnum] = idx++;
        lnum *= 10;
        res += abs(lnum / lde) + '0';
        lnum = lnum % lde;
    }
    return res;
}


int main(){
    cout << fractionToDecimal(1, 3) << endl;
}
