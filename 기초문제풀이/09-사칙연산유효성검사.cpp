#include<iostream>
using namespace std;

int main()
{
	int TC, N, i, idx, position, y, z;
	char cmd[19], x;
	for (TC = 0; TC < 10; TC++) {
		cin >> N;
		position = 1;

		for (i = 0; i < N; i++) {
			if (position == 0) {
				cin.getline(cmd, 17);
				continue;
			}
			
			cin >> idx;
			if (N > idx * 2) {
				cin >> x;
				if (x >= '0' && x <= '9') {
					position = 0;
					cin.getline(cmd, 17);
					continue;
				}

				cin >> y >> z;
			}
			else if (N < idx * 2) {
				cin >> x;
				if (x < '0' || x>'9') {
					position = 0;
					cin.getline(cmd, 17);
					continue;
				}
			}
			else {
				position = 0;
				cin.getline(cmd, 17);
				continue;
			}
		}

		cout << "#" << TC + 1 << " " << position << "\n";
	}
}
