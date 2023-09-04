int N;
int map[10][10];
bool visited[10][10];

typedef struct {
    int x, y, distance;
} Node;

Node queue[100];
int front = 0, rear = 0;

void push(Node node) {
    queue[rear++] = node;
}

Node pop() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

void bfs_init(int map_size, int input_map[10][10]) {
    N = map_size;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            map[i][j] = input_map[i][j];
        }
    }
}

int bfs(int x1, int y1, int x2, int y2) {
    // Å¥ ÃÊ±âÈ­
    front = 0;
    rear = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    push({ x1 - 1, y1 - 1, 0 });
    visited[y1 - 1][x1 - 1] = true;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!isEmpty()) {
        Node current = pop();

        if (current.x == x2 - 1 && current.y == y2 - 1) {
            return current.distance;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newY][newX] && map[newY][newX] == 0) {
                visited[newY][newX] = true;
                push({ newX, newY, current.distance + 1 });
            }
        }
    }

    return -1;
}
