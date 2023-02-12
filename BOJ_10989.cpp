#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int arr[10000] = { 0, };
    int idx = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> idx;
        ++arr[idx - 1];
    }

    for (int i = 0; i < 10000; ++i) {
        while (arr[i]) {
            cout << i + 1 << "\n";
            --arr[i];
        }
    }
    return 0;
}