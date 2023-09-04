/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int days[200001];
int maxPeriod;
vector<int> blanks;

int binary_search(int N, int P) {
	int i, s, e, answer, mid;
	for (i = 0; i < N; i++)
	{
		s = i, e = N - 1;
		answer = 0;
		while (s <= e) {
			mid = s + (e - s) / 2;
			int didntStudy = 0, curP = P;			// didntStudy : days[i] ��¥���� days[mid] ��¥���� �� ����(���� �� �� �ϼ�) / curP : days[i]���� days[mid]���� ���ӽ����� �� ���� p
			didntStudy = blanks[mid] - blanks[i];

			curP = (P - didntStudy > 0) ? P - didntStudy : 0;		// ���� p�� ������ 0���� ó��

			if (didntStudy > P)			// �߰��� üũ�� �� �ִ� ������ ���� ������ �� ���� -> days[mid] �̻��� ��¥�� �Ұ����ϹǷ� �� �Ʒ� ���� Ž��
				e = mid - 1;
			else                        // �߰��� üũ�� �� �ִ� ���� �� ���� ����߰ų�, �� ���� ��� -> days[i] ~ days[mid]�� ���� ���� �Ⱓ�� answer�� �����صΰ�, �� �� ���� Ž��
			{
				answer = days[mid] - days[i] + 1 + curP;
				s = mid + 1;
			}
		}
		if (maxPeriod < answer)
			maxPeriod = answer;
	}
	return maxPeriod;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, p;
		cin >> n >> p;

		for (int j = 0; j < n; j++)
		{
			int day;
			cin >> day;
			days[j] = day;
		}

		int blankCount = 0;
		blanks.clear();
		blanks.push_back(0);				// �� ù ��¥������ ���� X

		// blankCount�� ���� ���� ��¥�� ���� ���� ��¥ ������ ���� �����ϰ� �̸� blanks�� ����
		for (int j = 0; j < n - 1; j++)
		{
			blankCount += days[j + 1] - days[j] - 1;
			blanks.push_back(blankCount);
		}

		cout << '#' << i + 1 << ' ' << binary_search(n, p) << el;
		maxPeriod = 0;
	}
}
*/