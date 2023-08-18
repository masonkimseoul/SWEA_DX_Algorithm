/*
#include<iostream>
using namespace std;

typedef struct node {
	int elem;
	struct node* left, * right, * parent;
}node;

node* p;
int nodeCnt = 0, pf = 0, cnt = 0;

void postOrder(node* pos) {
	if (pos != 0) {
		postOrder(pos->left);
		cnt++;
		postOrder(pos->right);
	}
}

void nodeParent(node* pos, int data) {
	if (pos != 0) {
		nodeParent(pos->left, data);
		if (pos->elem == data) p = pos;
		nodeParent(pos->right, data);
	}
}

int main()
{
	int TC, i, j, V, E, child1, child2, edge1, edge2;
	int flag, cnt1, cnt2;
	node* f1, * f2, *tmp;
	cin >> TC;
	for (i = 0; i < TC; i++) {
		node nodePool[10000] = { 0 };
		
		cin >> V >> E >> child1 >> child2;
		for (j = 0; j < E; j++) {
			cin >> edge1 >> edge2;

			if (nodePool[edge1 - 1].left == 0) {
				nodePool[edge1 - 1].elem = edge1;
				nodePool[edge2 - 1].elem = edge2;
				nodePool[edge1 - 1].left = &nodePool[edge2 - 1];
				nodePool[edge2 - 1].parent = &nodePool[edge1 - 1];
			}
			else if (nodePool[edge1 - 1].right == 0) {
				nodePool[edge2 - 1].elem = edge2;
				nodePool[edge1 - 1].right = &nodePool[edge2 - 1];
				nodePool[edge2 - 1].parent = &nodePool[edge1 - 1];
			}
		}

		nodeParent(&nodePool[0], child1);
		f1 = p;
		nodeParent(&nodePool[0], child2);
		f2 = p;

		flag = 0;
		cnt1 = 0;
		cnt2 = 0;

		while (f1->parent != 0) {
			tmp = f2;
			while (tmp->parent != 0) {
				if (f1->parent == tmp->parent) {
					flag = 1;
					break;
				}
				tmp = tmp->parent;
			}
			if (flag == 1) break;
			f1 = f1->parent;
		}

		postOrder(f1->parent);
		cout << "#" << i + 1 << " " << f1->parent->elem << " " << cnt << "\n";
		cnt = 0;
		nodeCnt = 0;
	}
}
*/
