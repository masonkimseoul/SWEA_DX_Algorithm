/*
#include <unordered_map>
#include <string>
#define MAX_PARENT 14
#define MAX_DATE 1048576

using namespace std;
struct Node {
    struct Node* parent[MAX_PARENT];
    int depth;
};
unordered_map<string, Node> tree;
int power[MAX_PARENT], segment_tree[MAX_DATE * 2], N = 0;

void segment_tree_push(int idx, int left, int right, int a, int b) {
    if (right < a || b < left) return;

    int mid = (left + right) / 2;
    if (a <= left && right <= b) {
        segment_tree[idx] += 1;
        return;
    }
    segment_tree_push(idx * 2, left, mid, a, b);

    segment_tree_push(idx * 2 + 1, mid + 1, right, a, b);
}

void init(char mAncestor[], int mDeathday) {
    int i;
    tree.clear();

    power[0] = 1;
    
    for (i = 0; i < MAX_DATE * 2; i++) segment_tree[i] = 0;
    for (i = 1; i < MAX_PARENT; i++) power[i] = power[i - 1] * 2;

    segment_tree_push(1, 0, MAX_DATE - 1, 0, mDeathday);
}

int add(char mName[], char mParent[], int mBirthday, int mDeathday) {
    Node* node = &tree[mName];
    int i;

    node->parent[0] = &tree[mParent];
    node->depth = node->parent[0]->depth + 1;
    for (i = 1; i < MAX_PARENT; i++) {
        if (node->parent[i - 1] == NULL) break;
        node->parent[i] = node->parent[i - 1]->parent[i - 1];
    }
    segment_tree_push(1, 0, MAX_DATE - 1, mBirthday, mDeathday);

    return node->depth;
}

int distance(char mName1[], char mName2[]) {
    int dist = 0, i;
    Node* node_a = &tree[mName1];
    Node* node_b = &tree[mName2];

    if (node_a->depth < node_b->depth) {
        Node* tmp = node_a;
        node_a = node_b;
        node_b = tmp;
    }
    for (i = MAX_PARENT - 1; i >= 0; i--) {
        if (node_a->depth - node_b->depth >= power[i]) {
            dist += power[i];
            node_a = node_a->parent[i];
        }
    }

    for (i = MAX_PARENT - 1; i >= 0; i--) {
        if (node_a->parent[i] != node_b->parent[i]) {
            dist += power[i] * 2;
            node_a = node_a->parent[i];
            node_b = node_b->parent[i];
        }
    }

    return dist + (node_a != node_b ? 2 : 0);
}

int count(int mDay) {
    int cnt, index;
    cnt = 0;
    index = mDay + MAX_DATE;
    while (index > 0) {
        cnt += segment_tree[index];
        index /= 2;
    }

    return cnt;
}
*/