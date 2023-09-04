#include<iostream>
using namespace std;

int dp[1001][1001];

int compareString(string x, string y) {
	int i, j;
	for (i = 1; i <= x.size(); i++) {
		for (j = 1; j <= y.size(); j++) {
			if (x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[i - 1][j - 1];
}

int main()
{
	int T, TC, i, j;
	string str1, str2;
	cin >> TC;
	for (T = 0; T < TC; T++) {
		cin >> str1 >> str2;
		if (str1.size() > str2.size()) swap(str1, str2);

		for (i = 0; i <= str1.size(); i++) {
			for (j = 0; j <= str2.size(); j++) dp[i][j] = 0;
		}

		cout << "#" << T + 1 << " " << compareString(str1, str2) << "\n";
	}
}
