#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>

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
   const int n1 = mid - left + 1;
   const int n2 = right - mid;
   // the dimension need to be a constexpr
   // int L[n1], R[n2];
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

int quick_sort_partition(vector<int>& nums, int left, int right){
   // take the last element(nums[right]) as a pivot
   // place all the smaller elements to the left
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


void shell_sort(vector<int>& nums){
   // shell compare the element with decreasing gap
   // the initial gap would be like length/2;
   int n = nums.size();
   int gap = n / 2;
   while(gap>0){
      // for each gap, the element is in order
      for (int i = gap; i < n; i++){
         while(i-gap>=0 && nums[i]<nums[i-gap]){
            swap(nums[i], nums[i - gap]);
            i -= gap;
         }
      }
      // change gap every loop
      gap /= 2;
   }
}

void heapify(vector<int>& nums, int start, int end){
   // each heap is binary tree, which means its node can be represented as index in array.
   // for parent node, i->(2i+1, 2i+2);
   // for child node, i->(i-1)/2
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
   // the heapify maintain a big top pile
   int n = nums.size();
   // last element is n-1
   int bottom = (n - 1 - 1) / 2;
   // ensure parent value > child value
   for (int i = bottom; i >= 0;i--){
      heapify(nums, i, n-1);
   }
   // get element from top
   for (int i = n - 1; i > 0; i--){
      swap(nums[0], nums[i]);
      heapify(nums, 0, i-1);
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
   // merge_sort(a, 0, arr_size-1);
   // quicksort(a, 0, arr_size - 1);
   // shell_sort(a);
   // heap_sort(a);
   // radix_sort(a);
   counting_sort(a);
   print_array(a, arr_size);
   cout << endl;
   return 0;
}
