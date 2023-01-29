#include<iostream>
using namespace std;

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int arr[], const int& left, const int& right) {
    int pivot = arr[right];
    int leftIdx = left - 1;

    for (int idx = left; idx < right; ++idx) {
        if (arr[idx] <= pivot) {
            ++leftIdx;
            Swap(arr[leftIdx], arr[idx]);
        }
    }
    Swap(arr[++leftIdx], arr[right]);
    return leftIdx;
}

void QuickSort(int arr[], const int& left, const int& right) {
    if (left < right) {
        int partitionIdx = Partition(arr, left, right);
        QuickSort(arr, partitionIdx + 1, right);
        QuickSort(arr, left, partitionIdx - 1);
    }
}

int main() {
    int N = 0;    
    cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    QuickSort(arr, 0, N - 1);

    for (int i = 0; i < N; ++i) {
        cout << arr[i] << "\n";
    }

    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}