#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n = 0;
	cin >> n;
	int frequencyArray[8001] = { 0, };
	vector<int> numbers;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.emplace_back(temp);
		sum += temp;

		//최빈값 체크를 위해 temp값 자연수 범위로 변경
		temp += 4000;
		//빈도수 체크
		frequencyArray[temp]++;
	}
	sort(numbers.begin(), numbers.end());

	//산술평균값
	int avg = floor(sum / (n * 1.0) + 0.5);
	//중앙값 인덱스
	int midIdx = n / 2;
	//범위값
	int range = numbers[n - 1] - numbers[0];
	//최빈값
	int maxFrequency = 0;
	int max = -5000;

	//빈도체크 배열에서 가장 많은 빈도수 확인
	for (int i = 0; i < 8001; i++) {
		if (max < frequencyArray[i]) {
			max = frequencyArray[i];
		}
	}

	//최빈값이 여러개일 수 있으므로, 배열로 담기
	vector<int> maxFrequencyNum;
	for (int i = 0; i < 8001; i++) {
		if (max == frequencyArray[i]) {
			maxFrequencyNum.emplace_back(i);
		}
	}
	sort(maxFrequencyNum.begin(), maxFrequencyNum.end());

	//최빈값이 여러개면 2번째로 작은 값, 아니면 1번째 값 선택
	if (maxFrequencyNum.size() > 1) {
		maxFrequency = maxFrequencyNum[1] - 4000;
	}
	else {
		maxFrequency = maxFrequencyNum[0] - 4000;
	}

	cout << avg << endl;
	cout << numbers[midIdx] << endl;
	cout << maxFrequency << endl;
	cout << range;

	return 0;
}