#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void selection_sort(vector<int>& nums){
   int n = nums.size();
   int k = 0;
   for (int i = 0; i < n; i++){
      k = i;
      // find the index of minimum value
      for (int j = i+1; j < n; j++){
         if(nums[k]>nums[j]){
            k = j;
         }
      }
      swap(nums[i], nums[k]);
   }
}

void insert_sort(vector<int>& nums){
   int n = nums.size();
   int j = 0;
   for (int i = 0; i < n; i++){
      j = i+1;
      // if smaller, keep change the location of current element.
      while(j>0 && nums[j]<nums[j-1]){
         swap(nums[j], nums[j - 1]);
         j--;
      }
   }
}

void bubble_sort(vector<int>& nums){
   int n = nums.size();
   bool flag = false;
   for (int i = 1; i < n; i++){
      flag = false;
      for (int j = 0; j < n - i; j++){
         if(nums[j]>nums[j+1]){
            swap(nums[j], nums[j + 1]);
            flag = true;
         }
      }
      // if nothing happened, means array is sorted.
      if(!flag)
         break;
   }
}

void helper_merge(vector<int>& nums, int left, int mid, int right){
   int n1 = mid - left + 1;
   int n2 = right - mid + 1;
   int L[n1], R[n2];
   for (int i = 0; i < n1; i++){
      L[i] = nums[left + i];
   }
   for (int i = 0; i < n2; i++){
      R[i] = nums[mid + i];
   }
   int k = left;
   int p1 = 0, p2 = 0;
   while(p1<n1 && p2<n2){
      if(L[p1]>R[p2]){
         nums[k++] = R[p2];
      }else{
         nums[k++] = L[p1];
      }
   }
   while(p1<n1)
      nums[k++] = L[p1];
   while(p2<n2)
      nums[k++] = R[p2];
}

void merge_sort(vector<int>& nums,int left, int right){
   if(left>=right)
      return;
   int mid = (right - left)/2 + left;
   // index right is included
   merge_sort(nums, left, mid);
   merge_sort(nums, mid+1, right);
   helper_merge(nums, left, mid, right);
}


void print_array(vector<int>& nums, int arr_size){
   for (int i = 0; i < arr_size; i++){
      cout << nums[i] << " ";
   }
   cout << endl;
}

int main(){
   vector<int> a = {1, 23, 3, 4, 7, 90};
   int arr_size = sizeof(a) / sizeof(a[0]);
   // selection_sort(a);
   // insert_sort(a);
   // bubble_sort(a);
   merge_sort(a, 0, arr_size-1);
   print_array(a, arr_size);
   cout << endl;
   return 0;
}
