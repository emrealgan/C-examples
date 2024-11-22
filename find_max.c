int findMax(int* arr, int size) {
    int max = 0; // INT_MIN
    int index = 0;
    
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    
    return index;
}