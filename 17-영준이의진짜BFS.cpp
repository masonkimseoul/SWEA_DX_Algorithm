/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAXN 100005
int n;
int x[MAXN], y[MAXN][23];
bool check[MAXN];
vector<vector<int>> graph;

int lca(int a, int b) {
    if (x[b] > x[a]) swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if ((x[a] - x[b]) >= (1 << i)) a = y[a][i];
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (y[a][i] != y[b][i]) {
            a = y[a][i];
            b = y[b][i];
        }
    }
    return y[a][0];
}

void elem_sparse() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < n; j++) {
            y[j][i] = y[y[j][i - 1]][i - 1];
        }
    }
}



int main() {

    int TC, c = 1, i, tmp, now, depth, next, LCA;
    ll ret;
    scanf(" %d", &TC);
    while (TC--) {
        graph.clear();
        memset(check, 0, sizeof(check));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        
        scanf(" %d", &n);
        graph.resize(n + 3);

        for (i = 1; i < n; i++) {
            tmp; scanf(" %d", &tmp);
            graph[tmp - 1].push_back(i);
        }

        for (i = 0; i < n; i++) sort(graph[i].begin(), graph[i].end());

        check[0] = true;
        queue<pair<int, int>> dq;
        dq.push({ 0,0 });

        while (!dq.empty()) {
            now = dq.front().first;
            depth = dq.front().second;
            dq.pop();
            x[now] = depth;

            for (i = 0; i < graph[now].size(); i++) {
                next = graph[now][i];

                if (!check[next]) {
                    check[next] = true;
                    y[next][0] = now;

                    dq.push({ next,depth + 1 });
                }
            }
        }

        elem_sparse();

        ret = 0;
        memset(check, 0, sizeof(check));
        vector<int> vt;
        queue<int> q;
        q.push(0);

        check[0] = true;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            vt.push_back(now);
            for (i = 0; i < graph[now].size(); i++) {
                next = graph[now][i];
                if (!check[next]) {
                    check[next] = true;
                    q.push(next);
                }
            }
        }
        for (i = 0; i < n - 1; i++) {
            LCA = lca(vt[i], vt[i + 1]);
            ll a = x[vt[i]] - x[LCA];
            ll b = x[vt[i + 1]] - x[LCA];
            ret += a; ret += b;
        }

        printf("#%d %lld\n", c++, ret);
    }
}
*/