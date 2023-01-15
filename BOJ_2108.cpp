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

		//�ֺ� üũ�� ���� temp�� �ڿ��� ������ ����
		temp += 4000;
		//�󵵼� üũ
		frequencyArray[temp]++;
	}
	sort(numbers.begin(), numbers.end());

	//�����հ�
	int avg = floor(sum / (n * 1.0) + 0.5);
	//�߾Ӱ� �ε���
	int midIdx = n / 2;
	//������
	int range = numbers[n - 1] - numbers[0];
	//�ֺ�
	int maxFrequency = 0;
	int max = -5000;

	//��üũ �迭���� ���� ���� �󵵼� Ȯ��
	for (int i = 0; i < 8001; i++) {
		if (max < frequencyArray[i]) {
			max = frequencyArray[i];
		}
	}

	//�ֺ��� �������� �� �����Ƿ�, �迭�� ���
	vector<int> maxFrequencyNum;
	for (int i = 0; i < 8001; i++) {
		if (max == frequencyArray[i]) {
			maxFrequencyNum.emplace_back(i);
		}
	}
	sort(maxFrequencyNum.begin(), maxFrequencyNum.end());

	//�ֺ��� �������� 2��°�� ���� ��, �ƴϸ� 1��° �� ����
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