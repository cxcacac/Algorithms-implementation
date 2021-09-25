#include <cstdio>

using namespace std;

// not consider negative inputs
int numberOfOneInBinary(int n){
    int cnt = 0;
    while(n){
        if(n&1){
            ++cnt;
            n >>= 1;
        }
    }
    return cnt;
}

// consider negative inputs

int numberofOneInBinary2(int n){
    int cnt = 0;
    unsigned int flag = n;
    while(flag){
        if(n&flag){
            ++cnt;
        }
        flag <<= 1;
    }
    return cnt;
}

// consider all solutions
int numberOfOneInBinaryFinal(int n){
    int cnt = 0;
    while(n){
        ++cnt;
        n = n & (n - 1);
    }
}
