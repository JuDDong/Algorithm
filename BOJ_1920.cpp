#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool BinarySearch(const int& find, const vector<int>& A) {
	int maxIdx = A.size() - 1;
	int minIdx = 0;
	int midIdx = (maxIdx + minIdx) / 2;

	while (minIdx <= maxIdx) {
		if (A[midIdx] < find) {
			minIdx = midIdx + 1;
		}
		else if (A[midIdx] > find) {
			maxIdx = midIdx - 1;
		}
		else {
			return true;
		}

		midIdx = (maxIdx + minIdx) / 2;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<int> A;
	for (int i = 0; i < N; i++) {
		A.emplace_back();
		cin >> A.back();
	}
	sort(A.begin(), A.end());

	int M = 0, find = 0;
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> find;
		cout << BinarySearch(find, A) << "\n";
	}

	return 0;
}