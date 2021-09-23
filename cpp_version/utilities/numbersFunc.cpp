#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int  N){
    if(N<2)
        return false;
    int r = (int)sqrt(N);
    for (int i = 2; i <= r; i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

int getDigitSum(int num){
    int res = 0;
    while(num>0){
        res += num % 10;
        num /= 10;
    }
    return res;
}



int main(){
    cout << isPrime(3) << endl;
    cout << isPrime(452) << endl;
    cout << getDigitSum(452) << endl;
}
