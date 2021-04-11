#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H
#include <vector>
#include <iostream>
// vectors need to be declared in std;
using namespace std;

void selection_sort(vector<int> &nums);
void insert_sort(vector<int> &nums);
void bubble_sort(vector<int> &nums);
void helper_merge(vector<int> &nums, int left, int mid, int right);
void merge_sort(vector<int> &nums, int left, int right);

int quick_sort_partition(vector<int> &nums, int left, int right);
void quicksort(vector<int> &nums, int left, int right);

void shell_sort(vector<int> &nums);

void heapify(vector<int> &nums, int start, int end);
void heap_sort(vector<int> &nums);

int get_max(vector<int> &nums);
int get_min(vector<int> &nums);

void radix_sort_helper(vector<int> &nums, const int n, const int exp);
void radix_sort(vector<int> &nums);

void counting_sort(vector<int> &nums);
void print_array(vector<int> &nums, int arr_size);
#endif
