/*
#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

int adj[MAX_K + 2][MAX_CHILD];   // 각 노드에 연결된 자식 노드 목록을 저장
int adjSize[MAX_K + 2];          // 각 노드에 연결된 자식 노드의 개수를 저장
bool visited[MAX_K + 2];         // 각 노드의 방문 여부를 저장

void dfs_init(int N, int path[MAX_N][2]) {
    for (int i = 0; i < MAX_K + 2; i++) {
        adjSize[i] = 0;  // 초기에 각 노드의 자식 노드 개수는 0개입니다.
    }

    for (int i = 0; i < N; i++) {
        int parent = path[i][0];
        int child = path[i][1];
        adj[parent][adjSize[parent]] = child;  // 연결 정보 저장
        adjSize[parent]++;
    }
}

int recursiveDFS(int curr, int n) {
    if (visited[curr]) return -1;  // 이미 방문한 노드이면 -1 반환

    visited[curr] = true;

    // n보다 큰 값을 가진 노드를 찾았을 경우, 그 값을 반환
    if (curr > n) return curr;

    for (int i = 0; i < adjSize[curr]; i++) {
        int nextNode = adj[curr][i];
        int result = recursiveDFS(nextNode, n);  // 자식 노드로 재귀 호출
        if (result != -1) return result;  // n보다 큰 값을 가진 노드를 찾았을 경우 반환
    }

    return -1;  // n보다 큰 값을 가진 노드를 찾지 못했을 경우
}

int dfs(int n) {
    for (int i = 0; i < MAX_K + 2; i++) {
        visited[i] = false;  // 모든 노드의 방문 상태 초기화
    }

    return recursiveDFS(n, n);
}
*/