#include <iostream>
#include "sort_algorithm.h"

using namespace std;

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
