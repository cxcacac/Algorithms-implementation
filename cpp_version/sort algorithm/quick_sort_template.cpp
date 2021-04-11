template<class T>
void quicksort(T data[], int low, int high, int(*comp)(T, T)){
    int mid;
    if(low >= high)
        return;
    mid = divide(data, low, high, comp);
    quicksort(data, low, mid - 1, comp);
    quicksort(data, mid + 1, high, comp);
}

template<class T>
int divide(T data[], int low, int high, int (*comp)(T, T)){
    T k = data[low];

}
