#include <iostream>

// MUST ADD BRACKETS!!!
#define MOD (1e9 + 7)

using namespace std;

typedef long long ll;

// recursively
ll qpow_recursive(ll a, ll n){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        ll temp = qpow_recursive(a, n / 2) % (ll)MOD;
        return temp * temp % (ll)MOD;
    }
    else{
        return a * qpow_recursive(a, n-1) % (ll)MOD;
    }
}

//iteratively, repress n by binary form, and use iterations
ll qpow_iterative(ll a, ll n){
    // use tmp to represent power of a;
    ll tmp = a;
    ll res = 1;
    while(n>0){
        if(n%2==1){
            res = (res * tmp)% (ll)MOD;
        }
        tmp *= tmp;
        n >>= 1;
    }
    return res;
}

int main(){
    cout << qpow_recursive(2, 4) << endl;
    cout << qpow_iterative(2, 4) << endl;
}
