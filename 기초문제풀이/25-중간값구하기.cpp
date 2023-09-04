#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
ll T, N, a, sum;

int main()
{
	int TC, T, i, x, y;
	cin >> T;

	for (TC = 0; TC < T; TC++) {
		priority_queue<ll> pq1;
		priority_queue<ll, vector<ll>, greater<ll>> pq2;

		cin >> N >> a;
		sum = 0;
		pq1.push(a);
		pq2.push(a);

		for (i = 0; i < N; i++) {
			cin >> x >> y;

			if (pq1.top() > x) pq1.push(x);
			else pq2.push(x);

			if (pq1.top() > y) pq1.push(y);
			else pq2.push(y);

			if (pq1.size() == pq2.size()) {
				sum += (pq1.top()) % 20171109;
				continue;
			}
			else if (pq1.size() > pq2.size()) {
				pq1.pop();
				pq2.push(pq1.top());
			}
			else {
				pq2.pop();
				pq1.push(pq2.top());

			}
			sum += (pq1.top()) % 20171109;
		}

		sum %= 20171109;
		cout << "#" << TC + 1 << " " << sum << "\n";
	}
}
