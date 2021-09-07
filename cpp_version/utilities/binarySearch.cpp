#include<vector>
#include<iostream>

using namespace std;

// from leetcode 34

int lower_bound(const vector<int>& nums, int target){
    int l = 0, r = nums.size();
    while(l<r){
        int mid = (r - l) / 2 + l;
        if(nums[mid] >= target){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

int upper_bound(vector<int>& nums, int target){
    int l = 0, r = nums.size();
    while(l<r){
        int mid = (r - l) / 2 + l;
        if(nums[mid] <= target){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l - 1;
}

vector<int> searchRange(vector<int>& nums, int target){
    if(nums.empty())
        return {-1, -1};
    int l = lower_bound(nums, target);
    int r = upper_bound(nums, target);
    if(l==nums.size() || nums[l] != target){
        return {-1, -1};
    }
    return {l, r};
}
