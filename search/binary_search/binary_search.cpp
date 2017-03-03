// Binary Search implementation
//
// Wiki: 
//      https://en.wikipedia.org/wiki/Binary_search_algorithm
//
// Pavel Bazin 2017



bool binary_search(int arr[], int len, int key)
{       
    int left = 0;
    int right = len;

    while (left <= right) {
        int m = (left + right) / 2;

        if (arr[m] == key)
            return true;
        else if (arr[m] > key)
            right = m - 1;
        else
            left = m + 1;
    }

    return false;
}
