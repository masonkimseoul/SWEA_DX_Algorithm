#include <iostream>
#include <queue>
using namespace std;

int N, K, answer;
int num[11];

void GetAnswer() {
	int i;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, K));

	while (pq.top().second) {
		pair<int, int> pos = pq.top();
		pq.pop();

		pq.push(make_pair(pos.first + pos.second, 0));
		for (i = 0; i < N; i++) pq.push(make_pair(pos.first + pos.second % num[i], pos.second / num[i]));
	}
	answer = pq.top().first;
}

int main()
{
	int T, TC, i;
	cin >> T;
	for (TC = 0; TC < T; TC++) {
		cin >> N;
		for (i = 0; i < N; i++) cin >> num[i];
		cin >> K;
		GetAnswer();
		cout << "#" << TC + 1 << " " << answer << "\n";
	}
}
