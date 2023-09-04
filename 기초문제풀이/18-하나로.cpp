#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;
#define ll long long
#define MAX 1000 + 1

typedef struct Pos {
    ll x;
    ll y;
}Pos;

double E;
Pos P[MAX];
vector<pair<ll, pair<ll, ll>>> Edge;

ll N;
ll Answer;
ll Parent[MAX];

ll Calc_Dist(int i, int j) {
    ll dx = (P[i].x - P[j].x) * (P[i].x - P[j].x);
    ll dy = (P[i].y - P[j].y) * (P[i].y - P[j].y);

    return dx + dy;
}

void Initialize() {
    int i;
    memset(Parent, 0, sizeof(Parent));
    N = Answer = 0;
    E = 0.0;
    Edge.clear();

    for (i = 0; i < MAX; i++) {
        P[i].x = -1;
        P[i].y = -1;
    }
}

void Input() {
    int i, j;
    ll a;
    cin >> N;

    for (i = 1; i <= N; i++) {
        cin >> a;
        P[i].x = a;
    }
    for (i = 1; i <= N; i++) {
        cin >> a;
        P[i].y = a;
    }

    for (i = 1; i <= N; i++) {
        for (j = i + 1; j <= N; j++) {
            ll Dist = Calc_Dist(i, j);
            Edge.push_back(make_pair(Dist, make_pair(i, j)));
        }
    }
    cin >> E;
}

int Find(int x) {
    if (Parent[x] == x) return x;
    else return Parent[x] = Find(Parent[x]);
}

bool SameParent(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) return false;
    else return true;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) Parent[y] = x;
}

void Solution() {
    int i;

    sort(Edge.begin(), Edge.end());

    for (i = 1; i <= N; i++) Parent[i] = i;

    for (i = 0; i < Edge.size(); i++) {
        if (SameParent(Edge[i].second.first, Edge[i].second.second) == false) {
            Union(Edge[i].second.first, Edge[i].second.second);
            Answer = Answer + Edge[i].first;
        }
    }
}

void Solve() {
    int TC, T;
    cin >> TC;
    for (T = 0; T < TC; T++) {
        Initialize();
        Input();
        Solution();

        cout << "#" << T + 1 << " " << (double)(Answer * E) << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout.precision(0);

    Solve();
}
