#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1};
int map[100][100];
int dp[100][100];
bool check[100][100];
int N;

int bfs() {
    int x, y, nx, ny, i;
    queue <pair <int, int>> q;
    check[0][0] = true;
    dp[0][0] = 0;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (check[nx][ny] == false || dp[nx][ny] > dp[x][y] + map[nx][ny]){
                    check[nx][ny] = true;
                    dp[nx][ny] = dp[x][y] + map[nx][ny];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    return dp[N - 1][N - 1];
}

int main()
{
    int TC, T, i, j;
    string s;
    cin >> T;
    for (TC = 0; TC < T; TC++) {
        memset(map, 0, sizeof(map));
        memset(dp, 0, sizeof(dp));
        memset(check, false, sizeof(check));
        cin >> N;

        for (i = 0; i < N; i++) {
            cin >> s;
            for (j = 0; j < N; j++) map[i][j] = s[j] - '0';
        }
        cout << "#" << TC + 1 << " " << bfs() << "\n";
    }
}
