#include <iostream>
#include <cmath>

using namespace std;

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent1(double base, unsigned int exponent);
double PowerWithUnsignedExponent2(double base, unsigned int exponent);
double Power(double base, int exponent);

int main(int argc, char* argv[]){
    cout << Power(0, -1) << endl;
    if(g_InvalidInput){
        cout << "InvalidInput" << endl;
    }
    cout << Power(1, -1) << endl;
    if(g_InvalidInput){
        cout << "InvalidInput" << endl;
    }
    cout << Power(1.1, 3) << endl;
    cout << pow(1.1, 3) << endl;
}

bool equal(double num1, double num2){
    if(abs(num1-num2)<1e-5){
        return true;
    }
    return false;
}

double Power(double base, int exponent){
    // remember to reset the global variables;
    g_InvalidInput = false;
    if(equal(base, 0.0) && exponent < 0){
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)exponent;
    double resultRecursive = PowerWithUnsignedExponent1(base, absExponent);
    double resultIterative = PowerWithUnsignedExponent2(base, absExponent);
    if(exponent<0){
        resultRecursive = 1 / resultRecursive;
        resultIterative = 1 / resultIterative;
    }
    cout << "Recursive:" << resultRecursive << endl;
    cout << "Iterative:" << resultIterative << endl;
    if(equal(resultIterative, resultRecursive)){
        return resultIterative;
    }
    else{
        g_InvalidInput = true;
        return 0.0;
    }
}

double PowerWithUnsignedExponent1(double base, unsigned int exponent){
    if(exponent==0){
        return 1.0;
    }
    if(exponent==1){
        return base;
    }
    double result = PowerWithUnsignedExponent1(base, exponent >> 1);
    result *= result;
    if((exponent & 1)==1){
        result *= base;
    }
    return result;
}

double PowerWithUnsignedExponent2(double base, unsigned int exponent){
    double tmp = base;
    double res = 1.0;
    while(exponent > 0){
        if((exponent & 1)==1){
            res *= tmp;
        }
        tmp *= tmp;
        exponent >>= 1;
    }
    return res;
}
