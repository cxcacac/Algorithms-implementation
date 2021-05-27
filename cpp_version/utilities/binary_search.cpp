#include<vector>
#include<iostream>

using namespace std;


int binarySearch_right_bound(const vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left<right){
        int mid = (left + right) >> 1;
        if(nums[mid]<=target){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return right - 1;
}
int binarySearch_lower_bound(const vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left<=right){
        int mid = (left + right) >> 1;
        if(nums[mid]<=target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return left;
}


int main(){
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 2, 2, 4};
    vector<int> c = {1, 2, 3, 6, 9};
    cout << binarySearch_right_bound(a, 2) << endl;
    cout << binarySearch_lower_bound(c, 5) << endl;
    return 0;
}
