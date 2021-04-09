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

void merge_sort(vector<int>& nums){

}


int main(){
   vector<int> a = {1, 23, 3, 4, 7, 90};
   // selection_sort(a);
   // insert_sort(a);
   // bubble_sort(a);

   int arr_size = sizeof(a) / sizeof(a[0]);
   for (int i = 0; i < arr_size ;i++){
      cout << a[i]<<" ";
   }
   cout << endl;
   return 0;
}
