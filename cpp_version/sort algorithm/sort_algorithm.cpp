// #define NDEBUG
// cpp name is consistent with header
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <cassert>

using namespace std;

int getMax(vector<int>& nums){
   return *max_element(nums.begin(), nums.end());
}

int getMin(vector<int>& nums){
   return *min_element(nums.begin(), nums.end());
}

void selectionSort(vector<int>& nums){
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

void insertSort(vector<int>& nums){
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

void bubbleSort(vector<int>& nums){
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
      if(!flag)
         break;
   }
}

void mergeSort(vector<int>& nums, int left, int right){
   // right included.
   if(left>=right)
      return;

   int mid = (right - left)/2 + left;
   vector<int> tmp(right-left+1);
   mergeSort(nums, left, mid);
   mergeSort(nums, mid+1, right);

   int i = left, j = mid+1;
   int idx = 0;
   while (i <= mid || j <= right){
      if(j>right||nums[i]<=nums[j]){
         tmp[idx++] = nums[i++];
      }
      else if(i>mid||nums[i]>nums[j]){
         tmp[idx++] = nums[j++];
      }
   }
   for (int i = left; i <= right; i++){
      nums[i] = tmp[i-left];
   }
}


void quickSort(vector<int>& nums, int left, int right){
   // right index included
   if(left>=right)
      return;
   int pivot = nums[right];
   int idx = left;
   for (int i = left; i < right; i++){
      if(nums[i] < pivot){
         swap(nums[i], nums[idx]);
         idx++;
      }
   }
   swap(nums[idx], nums[right]);
   quickSort(nums, left, idx - 1);
   quickSort(nums, idx+1, right);
}

/*
   - shell compare the element with decreasing gap.
   - the initial gap would be length/2, and gap = gap/2 for every loop until gap == 0;
   - for each gap, the element is in order
 */

void shellSort(vector<int>& nums){
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
   int m = getMax(nums);
   int n = nums.size();
   for (int exp = 1; m / exp > 0; exp*=10){
      radix_sort_helper(nums, n, exp);
   }
}

void counting_sort(vector<int>& nums){
   // creating large number of space.
   // space complexity: O(large)-O(small)
   int left = getMin(nums), right = getMax(nums);
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

void print_array(vector<int>& nums, int l, int r){
   for (int i = l; i <= r; i++){
      cout << nums[i] << " ";
   }
}

int main(){
   vector<int> nums;
   int num;
   while(cin>>num){
      nums.push_back(num);
   }
   int size = nums.size();
   cout << size << endl;
   // merge_sort(nums, 0, size-1);
   quickSort(nums, 0, size - 1);
   print_array(nums, 0, size - 1);
}
