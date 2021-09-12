## Several sorting algorithm

### Selection sort

The array can be viewed as two parts:

`[sorted|current idx|unsorted]`

**Principle**: Select the minimum value in the rest unsorted part and place it at the current idx.

Time complexity: `O(n^2)`

**Stable or not: unstable, selection sort will swap values directly, which will change relative position of same value.**

### Insert sort

The array can be viewed as two parts:

`[sorted|current idx|unsorted]`

**Principle**: Select current idx value, place it at the proper index at sorted part by comparing with adjacent element.

Time complexity: `O(n^2)`

**Stable or not: **

### Bubble sort

The array can be viewed as two parts:

`[unsorted|unsorted]`

**Principle**: compare adjacent value, larger value bubble up, when no one bubble up, break the loop (optimization) .

Time complexity: `O(n^2)`

**Stable or not：Stable, same value will not exchange postions**

### Merge sort

Merge sort is based on divide and conquer method.

We Divide the array into two parts, and connect every part together use two pointers.

`[[part1][part2]....]`

Time complexity：`O(nlogn)`

**Stable or not**: Stable, merge does not change relative position of same values.

### Shell sort

Shell sort compare values with decreasing gap, the first gap equals n/2, then decrease gap by 1/2, then follow the processing logic of insertion sort;

Time complexity: `O(nlogn)`，n/2 + n/4 + n/8 + n/16 + .... + n/n = n(1/2 + 1/4 + 1/8 + 1/16 + ... + 1/n) = nlogn (Harmonic Series)

Stable or not: unstable, gap change will change relative position.

### Heap sort

For binary tree, use array to represent the relations of parent nodes and child nodes. 

- P = floor(i/2)
- Lchild = 2*i+1
- Rchild =2*i+2

Principle:  Loop about two steps:

`[unsorted | sorted]`

- Build large-top-heap, heapify the unsort part;
- Rearrange the largest element to the back of array;

