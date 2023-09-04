/*
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, TC, N, M, cnt, i;
	string s;
	
	cin >> T;
	for (TC = 0; TC < T; TC++) {
		unordered_map<string, string> hash;
		cin >> N >> M;
		cnt = 0;
		for (i = 0; i < N; i++) {
			cin >> s;
			hash.insert({ s,s });
		}

		for (i = 0; i < M; i++) {
			cin >> s;
			if (hash.find(s) != hash.end()) cnt++;
		}

		cout << "#" << TC + 1 << " " << cnt << "\n";
	}
}
*/