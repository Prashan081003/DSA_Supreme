#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Temporary vectors to store the two halves
    vector<int> first(len1);
    vector<int> second(len2);

    // Copy data to temporary vectors
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge the two sorted vectors
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy remaining elements of the first vector, if any
    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    // Copy remaining elements of the second vector, if any
    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void mergeSort(vector<int>& arr, int s, int e) {
    if (s >= e) return;  // Base case: one or no elements

    int mid = (s + e) / 2;

    // Recursively sort the left and right halves
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, e);
}

int main() {
    cout << "Hello world!" << endl;
    vector<int> arr = {2, 5, 1, 6, 9};

    mergeSort(arr, 0, arr.size() - 1);

    for (int num : arr) {
        cout << " " << num << " ";
    }
    cout << endl;
    return 0;
}
