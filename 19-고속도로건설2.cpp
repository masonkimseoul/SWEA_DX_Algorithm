/*
#include<iostream>
#define ll long long

using namespace std;

struct node {
	int x, y, cost;
	node() :
		x(0), y(0), cost(0) {};
	node(int nx, int ny, int ncost) {
		x = nx;
		y = ny;
		cost = ncost;
	};
};

node nodePool[200005];
int length = 0, graph[50005];

void push(node newNode) {
	int child, parent;
	node tmp;

	nodePool[++length] = newNode;
	if (length == 0) return;

	child = length;
	parent = child / 2;
	while (nodePool[parent].cost > nodePool[child].cost && parent > 0) {
		tmp = nodePool[child];
		nodePool[child] = nodePool[parent];
		nodePool[parent] = tmp;

		child = parent;
		parent = child / 2;
	}
}

int find(int a, int* ar) {
	if (a == ar[a]) return a;
	return ar[a] = find(ar[a], ar);
}

void unionGraph(int a, int b, int* ar) {
	ar[find(b, ar)] = find(a, ar);
}

node pop(node* ar) {
	node answer = ar[1], tmp;
	int parent = 1, child = parent * 2;

	ar[1] = nodePool[length--];
	if (child + 1 <= length) child = nodePool[child].cost <= nodePool[child + 1].cost ? child : child + 1;

	while (nodePool[child].cost < nodePool[parent].cost && child < length) {
		tmp = nodePool[child];
		nodePool[child] = nodePool[parent];
		nodePool[parent] = tmp;
		parent = child;
		child = parent * 2;

		if (child + 1 <= length) child = nodePool[child].cost <= nodePool[child + 1].cost ? child : child + 1;
	}

	return answer;
}

int main()
{
	int TC, T, i, j, N, M, cnt, x, y, cost;
	ll result;
	node s, pos;

	cin >> T;
	for (TC = 0; TC < T; TC++) {
		for (i = 0; i < 50005; i++) graph[i] = i;
		result = 0;
		cnt = 2;
		length = 0;

		cin >> N >> M;
		for (j = 0; j < M; j++) {
			cin >> x >> y >> cost;
			node nodes(x, y, cost);
			push(nodes);
		}

		s = pop(nodePool);
		unionGraph(s.x, s.y, graph);
		result += s.cost;

		while (cnt < N) {
			pos = pop(nodePool);
			if (find(s.x, graph) != find(pos.x, graph) || find(s.x, graph) != find(pos.y, graph)) {
				if (find(s.x, graph) != find(pos.x, graph)) cnt++;
				if (find(s.x, graph) != find(pos.y, graph)) cnt++;

				unionGraph(s.x, pos.x, graph);
				unionGraph(s.x, pos.y, graph);
				result += pos.cost;
			}
		}
		cout << "#" << TC + 1 << " " << result << "\n";
	}
}
*/