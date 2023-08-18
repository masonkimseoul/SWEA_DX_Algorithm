/*
#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

int adj[MAX_K + 2][MAX_CHILD];   // �� ��忡 ����� �ڽ� ��� ����� ����
int adjSize[MAX_K + 2];          // �� ��忡 ����� �ڽ� ����� ������ ����
bool visited[MAX_K + 2];         // �� ����� �湮 ���θ� ����

void dfs_init(int N, int path[MAX_N][2]) {
    for (int i = 0; i < MAX_K + 2; i++) {
        adjSize[i] = 0;  // �ʱ⿡ �� ����� �ڽ� ��� ������ 0���Դϴ�.
    }

    for (int i = 0; i < N; i++) {
        int parent = path[i][0];
        int child = path[i][1];
        adj[parent][adjSize[parent]] = child;  // ���� ���� ����
        adjSize[parent]++;
    }
}

int recursiveDFS(int curr, int n) {
    if (visited[curr]) return -1;  // �̹� �湮�� ����̸� -1 ��ȯ

    visited[curr] = true;

    // n���� ū ���� ���� ��带 ã���� ���, �� ���� ��ȯ
    if (curr > n) return curr;

    for (int i = 0; i < adjSize[curr]; i++) {
        int nextNode = adj[curr][i];
        int result = recursiveDFS(nextNode, n);  // �ڽ� ���� ��� ȣ��
        if (result != -1) return result;  // n���� ū ���� ���� ��带 ã���� ��� ��ȯ
    }

    return -1;  // n���� ū ���� ���� ��带 ã�� ������ ���
}

int dfs(int n) {
    for (int i = 0; i < MAX_K + 2; i++) {
        visited[i] = false;  // ��� ����� �湮 ���� �ʱ�ȭ
    }

    return recursiveDFS(n, n);
}
*/