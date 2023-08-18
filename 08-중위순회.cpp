/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

void inorder(char *tree, int *isFilled, int idx) {
	if (isFilled[idx*2] == 1) inorder(tree, isFilled, idx * 2);
	if (isFilled[idx] == 1) cout << tree[idx];
	if (isFilled[idx*2 + 1] == 1)inorder(tree, isFilled, idx * 2 + 1);
}


int main()
{
	int TC, N, i, left, right, vsize;
	char tree[101];
	int isFilled[101] = { 0 };
	string line, s;
	vector<string> cmd;

	for (TC = 0; TC < 10; TC++) {
		cin >> N;
		cin.ignore();
		for (i = 0; i < N; i++) {
			getline(cin, line);
			istringstream iss(line);
			
			while (iss >> s) cmd.push_back(s);

			tree[stoi(cmd[0])] = cmd[1].c_str()[0];
			isFilled[stoi(cmd[0])] = 1;
			cmd.clear();
		}

		cout << "#" << TC + 1 << " ";

		inorder(tree, isFilled, 1);
		cout << "\n";

		for (i = 0; i <= N; i++) isFilled[i] = 0;
		for (i = 0; i <= N; i++) tree[i] = NULL;
	}
}
*/