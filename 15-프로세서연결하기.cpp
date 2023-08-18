/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
struct info {
	int x, y;
};
info tmp;
vector<info> q;
int num, maxConn, minLength;
int arr[12][12];

void dfs(int idx, int len, int conn) {
	int nx, ny, cnt, i;

	if (idx == q.size()) {
		if (conn > maxConn) {
			minLength = len;
			maxConn = conn;
		}
		else if (conn == maxConn) minLength = min(minLength, len);
		return;
	}
	for (i = 0; i < 4; i++) {
		nx = q[idx].x;
		ny = q[idx].y;
		cnt = 0;
		while (1) {
			nx += dx[i];
			ny += dy[i];
			cnt++;
			if (arr[ny][nx] == 1 || arr[ny][nx] == 2) {
				cnt = 0;
				break;
			}
			if (arr[ny][nx] == 0 && (nx == 0 || ny == 0 || nx == num - 1 || ny == num - 1)) {
				break;
			}
		}
		if (cnt > 0) {
			nx = q[idx].x;
			ny = q[idx].y;
			while (1) {
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || ny < 0 || nx > num - 1 || ny > num - 1) break;
				arr[ny][nx] = 2;
			}
			dfs(idx + 1, len + cnt, conn + 1);
			nx = q[idx].x;
			ny = q[idx].y;
			while (1) {
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || ny < 0 || nx > num - 1 || ny > num - 1) break;
				arr[ny][nx] = 0;
			}
		}
	}
	dfs(idx + 1, len, conn);
}

int main() {
	int test, tc, i, j;
	cin >> test;
	for (tc = 0; tc <= test; tc++) {
		cin >> num;
		q.clear();
		for (i = 0; i < num; i++)
			for (j = 0; j < num; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					if (i == 0 || i == num - 1 || j == 0 || j == num - 1) continue;
					tmp.x = j;
					tmp.y = i;
					q.push_back(tmp);
				}
			}
		maxConn = 0;
		minLength = 987654321;
		dfs(0, 0, 0);
		cout << "#" << tc + 1 << " " << minLength << '\n';
	}
}
*/
