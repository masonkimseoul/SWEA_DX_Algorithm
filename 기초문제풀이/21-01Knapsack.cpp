#include<iostream>
using namespace std;

int main()
{
	int T, TC, i, j, N, K, knapsack[101][2], dp[101][1001], val;
	cin >> TC;
	for (T = 0; T < TC; T++) {
		cin >> N >> K;
		val = 0;
		for (i = 1; i <= N; i++) cin >> knapsack[i][0] >> knapsack[i][1];
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= K; j++) {
				if (knapsack[i][0] > j) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = max(knapsack[i][1] + dp[i - 1][j - knapsack[i][0]], dp[i - 1][j]);
			}
		}

		cout << "#" << T + 1 << " " << dp[N][K] << "\n";
	}
}
