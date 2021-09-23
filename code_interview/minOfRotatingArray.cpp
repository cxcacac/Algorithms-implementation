#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int minOfRotatingArray(int* numbers, int length){
    if(numbers==nullptr || length==0){
        logic_error e("invalid input");
        throw new exception(e);
    }
    int left = 0, right = length - 1;
    while(left<right){
        int mid = (right - left) / 2 + left;
        if(numbers[mid] > numbers[0]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return numbers[left];
}


int main(){
    int array[] = {4, 4, 5, 6, 2, 3};
    int length = sizeof(array) / (sizeof(array[0]));
    cout << minOfRotatingArray(array, length);
}
