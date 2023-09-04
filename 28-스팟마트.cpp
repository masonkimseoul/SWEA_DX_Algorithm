/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int N, M;
int ar[3002], ar2[102];
int dp[3002][102][102][2];

int take(int a, int i, int j, int chosen) {
    int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
    
    if (dp[a][i][j][chosen] != -1) return dp[a][i][j][chosen];
    
    if (chosen) {
        if (a < N) val1 = take(a + 1, i, j, 0);
        if (i + j < M) val2 = take(a, i, j + 1, 0);
    }
    else {
        if (a < N) {
            val1 = take(a + 1, i, j, 1) + ar[a];
            val2 = take(a + 1, i, j, 0);
        }

        if (i + j < M) {
            val3 = take(a, i + 1, j, 1) + ar2[i];
            val4 = take(a, i + 1, j, 0);
        }
    }
    dp[a][i][j][chosen] = max(val1, max(val2, max(val3, val4)));
    return dp[a][i][j][chosen];
}

int main()
{
    int TC, T, i;
    cin >> T;
    for (TC = 0; TC < T; TC++) {
        memset(dp, -1, sizeof(dp));
        memset(ar2, 0, sizeof(ar2));
        cout << "#" << TC + 1 << " ";

        cin >> N;
        for (i = 0; i < N; i++) cin >> ar[i];

        cin >> M;
        for (i = 0; i < M; i++) cin >> ar2[i];

        sort(ar2, ar2 + 102, greater<int>());
        cout << take(0, 0, 0, 0) << "\n";
    }
}
*/