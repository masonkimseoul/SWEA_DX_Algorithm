#define MAX_N 40
#define MAX_K 98
#define MIN_N 2
#define MAX_CHILD 5

int adj[MAX_K + 2][MAX_CHILD];
int adjSize[MAX_K + 2];
bool visited[MAX_K + 2];

void dfs_init(int N, int path[MAX_N][2]) {
    for (int i = 0; i < MAX_K + 2; i++) adjSize[i] = 0;

    for (int i = 0; i < N; i++) {
        int parent = path[i][0];
        int child = path[i][1];
        adj[parent][adjSize[parent]] = child;
        adjSize[parent]++;
    }
}

int recursiveDFS(int curr, int n) {
    if (visited[curr]) return -1;

    visited[curr] = true;

    if (curr > n) return curr;

    for (int i = 0; i < adjSize[curr]; i++) {
        int nextNode = adj[curr][i];
        int result = recursiveDFS(nextNode, n);
        if (result != -1) return result;
    }

    return -1;
}

int dfs(int n) {
    for (int i = 0; i < MAX_K + 2; i++) visited[i] = false;

    return recursiveDFS(n, n);
}
