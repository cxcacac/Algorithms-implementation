#include <iostream>
#include <cstring>

using namespace std;

bool Increment(char *num);
void PrintNumber(char *num);

void print1ToMaxNDigits(int n){
    if(n <= 0){
        return;
    }
    char *number = new char[n + 1];
    // memset(number, '0', n), n = sizeof(string), return the number of bytes in memory
    memset(number, '0', n);
    number[n] = '\0';
    while(!Increment(number)){
        PrintNumber(number);
    }
    delete[] number;
}

bool Increment(char* number){
    bool isOverFlow = false;
    int nLength = strlen(number);
    int carry = 0;
    for (int i = nLength - 1; i >= 0; i--){
        int nSum = number[i] - '0' + carry;
        if(i==nLength-1){
            nSum++;
        }
        if(nSum >= 10){
            if(i==0){
                isOverFlow = true;
            }
            else{
                nSum -= 10;
                carry = 1;
                number[i] = '0' + nSum;
            }
        }
        else{
            carry = 0;
            number[i] = '0' + nSum;
        }
    }
    return isOverFlow;
}

void PrintNumber(char* number){
    bool isBeginingZero = true;
    int nLength = strlen(number);
    for (int i = 0; i < nLength; i++){
        if(isBeginingZero && number[i] != '0'){
            isBeginingZero = false;
        }
        if(!isBeginingZero){
            printf("%c", number[i]);
        }
    }
    printf("\t");
}

int main(){
    print1ToMaxNDigits(3);
}
