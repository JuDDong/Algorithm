#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool BinarySearch(int *&arr, int arrSize, int target) {
    int left = 0;
    int right = arrSize - 1;
    int mid = (left + right) / 2;

    while (left <= right) {
        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int* arrN = new int[N];
    memset(arrN, 0, sizeof(int) * N);

    for (int i = 0; i < N; ++i) {
        cin >> arrN[i];
    }

    sort(arrN, arrN + N);

    int M;
    cin >> M;
    int* arrM = new int[M];
    memset(arrM, 0, sizeof(int) * M);
    
    for (int i = 0; i < M; ++i) {
        cin >> arrM[i];
    }

    bool check = false;
    for (int i = 0; i < M; ++i) {
        check = BinarySearch(arrN, N, arrM[i]);
        cout << check << " ";
    }

    if (nullptr != arrN) {
        delete[] arrN;
        arrN = nullptr;
    }

    if (nullptr != arrM) {
        delete[] arrM;
        arrM = nullptr;
    }

    return 0;
}