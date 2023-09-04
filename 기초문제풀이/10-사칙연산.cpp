/*
#include<iostream>
using namespace std;

typedef struct node {
	int elem, child[2];
	bool isNumber;
}node;

node nodePool[1000];

double calculate(int idx) {
	double x, y;
	
	if (nodePool[idx].isNumber) return (double)nodePool[idx].elem;

	x = calculate(nodePool[idx].child[0]);
	y = calculate(nodePool[idx].child[1]);

	if (nodePool[idx].elem == '+') return x + y;
	else if (nodePool[idx].elem == '-') return x - y;
	else if (nodePool[idx].elem == '*') return x * y;
	else if (nodePool[idx].elem == '/') return x / y;
	else return -1;
}

int main()
{
	int TC, N, idx, i, j, data, a, b;
	char cmd[10];

	for (TC = 0; TC < 10; TC++) {
		cin >> N;
		
		for (i = 0; i < N; i++) {
			cin >> idx;
			cin >> cmd;

			if ('0' <= cmd[0] && cmd[0] <= '9') {
				nodePool[--idx].isNumber = true;
				data = 0;
				for (j = 0; cmd[j]; j++) {
					data *= 10;
					data += cmd[j] - '0';
				}

				nodePool[idx].elem = data;
			}
			else {
				cin >> a >> b;

				nodePool[--idx].isNumber = false;
				data = cmd[0];
				
				nodePool[idx].elem = data;
				nodePool[idx].child[0] = --a;
				nodePool[idx].child[1] = --b;
			}
		}

		cout << "#" << TC + 1 << " " << calculate(0) << "\n";
	}
}
*/
