// #define NDEBUG
// cpp name is consistent with header
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <cassert>
// header file included
#include "sort_algorithm.h"

using namespace std;

// select the minimum value after current index, and swap. [sorted, unsorted]
void selection_sort(vector<int>& nums){
   int n = nums.size();
   int k = 0;
   for (int i = 0; i < n; i++){
      k = i;
      for (int j = i+1; j < n; j++){
         if(nums[k]>nums[j]){
            k = j;
         }
      }
      swap(nums[i], nums[k]);
   }
}

// insert the value to the sorted part. [sorted...unsorted]
void insert_sort(vector<int>& nums){
   int n = nums.size();
   int j = 0;
   for (int i = 0; i < n; i++){
      j = i+1;
      while(j>0 && nums[j]<nums[j-1]){
         swap(nums[j], nums[j - 1]);
         j--;
      }
   }
}

// bubble up the value to sorted part. [unsorted, sorted]
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
      // if nothing happened, elements are in order.
      if(!flag)
         break;
   }
}

// divide and conqure, change array to small parts, use ptr to connect.
void helper_merge(vector<int>& nums, int left, int mid, int right){
   const int n1 = mid - left + 1;
   const int n2 = right - mid;
   vector<int> L(n1), R(n2);
   for (int i = 0; i < n1; i++){
      L[i] = nums[left + i];
   }
   for (int i = 0; i < n2; i++){
      R[i] = nums[mid + i + 1];
   }
   int k = left;
   int p1 = 0, p2 = 0;
   while(p1<n1 && p2<n2){
      if(L[p1]>R[p2]){
         nums[k] = R[p2];
         p2++;
      }
      else{
         nums[k] = L[p1];
         p1++;
      }
      k++;
   }
   while(p1<n1)
      nums[k++] = L[p1++];
   while(p2<n2)
      nums[k++] = R[p2++];
}
void merge_sort(vector<int>& nums, int left, int right){
   if(left>=right)
      return;
   int mid = (right - left)/2 + left;
   // index right is included
   merge_sort(nums, left, mid);
   merge_sort(nums, mid+1, right);
   helper_merge(nums, left, mid, right);
}

/*
   - divide and conquer, use the last element as pivot.
   - use ptr(smaller_index) to represent the location of values less than pivot.
   - in partition, we must return the index at divisions.
 */
int quick_sort_partition(vector<int>& nums, int left, int right){
   int pivot = nums[right];
   int smaller_index = 0;
   for (int i = 0; i < right; i++){
      if(nums[i]<pivot){
         swap(nums[i], nums[smaller_index]);
         smaller_index++;
      }
   }
   swap(nums[smaller_index], nums[right]);
   return smaller_index;
}
void quicksort(vector<int>& nums, int left, int right){
   if(left>=right)
      return;
   int sep = quick_sort_partition(nums, left, right);
   quicksort(nums, left, sep-1);
   quicksort(nums, sep+1, right);
}

/*
   - shell compare the element with decreasing gap.
   - the initial gap would be length/2, and gap = gap/2 for every loop until gap == 0;
   - for each gap, the element is in order
 */

void shell_sort(vector<int>& nums){
   int n = nums.size();
   int gap = n / 2;
   while(gap>0){
      for (int i = gap; i < n; i++){
         while(i-gap>=0 && nums[i]<nums[i-gap]){
            swap(nums[i], nums[i - gap]);
            i -= gap;
         }
      }
      gap /= 2;
   }
}

/*
   - each heap is binary tree, we can use array to represent a tree;
   - Index relations:
      for parent node, i->(2i+1, 2i+2);
      for child node, i->(i-1)/2
   - heapify means arrange values which conforms to the codes of heap;
*/

void heapify(vector<int>& nums, int start, int end){
   int root = start;
   int child = 2 * start + 1;
   while(child <= end){
      if (child + 1 <= end && nums[child] < nums[child+1]){
         // to get one child
         // swap location with the largest element with root
         child++;
      }
      if(nums[root] < nums[child]){
         swap(nums[root], nums[child]);
         root = child;
         child = 2 * root + 1;
      }else{
         break;
      }
   }
}
void heap_sort(vector<int>& nums){
   int n = nums.size();
   // last element is n-1
   int bottom = (n - 1 - 1) / 2;
   // ensure parent value > child value
   for (int i = bottom; i >= 0;i--){
      heapify(nums, i, n-1);
   }
   for (int i = n - 1; i > 0; i--){
      swap(nums[0], nums[i]);
      heapify(nums, 0, i-1);
   }
}

void radix_sort_helper(vector<int>& nums, const int n, const int exp){
   vector<int> output(n);
   int cnt[10] = {0};
   for (int i = 0; i < n; i++){
      cnt[(nums[i] / exp) % 10]++;
   }
   for (int i = 1; i < 10; i++){
      cnt[i] += cnt[i - 1];
   }
   for (int i = n-1; i >= 0; i--){
      int val = (nums[i] / exp) % 10;
      output[cnt[val]-1] = nums[i];
      cnt[val]--;
   }
   for (int i = 0; i < n;i++){
      nums[i] = output[i];
   }
}

void radix_sort(vector<int>& nums){
   int m = get_max(nums);
   int n = nums.size();
   for (int exp = 1; m / exp > 0; exp*=10){
      radix_sort_helper(nums, n, exp);
   }
}

void counting_sort(vector<int>& nums){
   // creating large number of space.
   // space complexity: O(large)-O(small)
   int left = get_min(nums), right = get_max(nums);
   int n = nums.size();
   // right and left included.
   vector<int> helper(right - left + 1, 0);
   for (int i = 0; i < n;  i++){
      helper[nums[i] - left]++;
   }
   int index = 0;
   for (int i = 0; i < right - left + 1; i++){
      while(helper[i]!=0){
         assert(index < n);
         nums[index] = i+left;
         index++;
         helper[i]--;
      }
   }
}

int get_max(vector<int>& nums){
   if(nums.empty())
      return 0;
   int max_value = nums[0];
   int n = nums.size();
   for (int i = 1; i < n; i++){
      max_value = max(max_value, nums[i]);
   }
   return max_value;
}

int get_min(vector<int>& nums){
   if(nums.empty())
      return 0;
   int min_value = nums[0];
   int n = nums.size();
   for (int i = 1; i < n; i++){
      min_value = min(min_value, nums[i]);
   }
   return min_value;
}

void print_array(vector<int>& nums, int arr_size){
   for (int i = 0; i < arr_size; i++){
      cout << nums[i] << " ";
   }
   cout << endl;
}

