
#include<iostream>
#include<cstring>

using namespace std;

typedef struct node {
	int x, y;
}node;

bool visited[300][300];
char map[300][300];
node queue[90000];

int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };

bool check(int x, int y, int N) {
	int i, nx, ny;
	for (i = 0; i < 8; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] == '*') return false;
		}
	}
	return true;
}

void BFS(int x, int y, int N) {
	int px = x, py = y, s = -1, e = 0, i, nx, ny;
	queue[e] = { px, py };
	visited[px][py] = true;

	while (s != e) {
		node tmp = queue[++s];

		for (i = 0; i < 8; i++) {
			nx = tmp.x + dx[i];
			ny = tmp.y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (visited[nx][ny]) continue;
				visited[nx][ny] = true;
				if (check(nx, ny, N)) queue[++e] = { nx, ny };
			}
		}
	}
}

int main()
{
	int T, TC, N, i, j, answer;
	char data;
	cin >> T;
	for (TC = 0; TC < T; TC++) {
		cin >> N;

		memset(map, '.', sizeof(map));
		memset(visited, false, sizeof(visited));

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				cin >> data;
				map[i][j] = data;
				if (data == '*') visited[i][j] = true;
			}
		}

		answer = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (check(i, j, N) && !visited[i][j]) {
					BFS(i, j, N);
					answer++;
				}
			}
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (!visited[i][j]) answer++;
			}
		}

		cout << "#" << TC + 1 << " " << answer << "\n";
	}
}