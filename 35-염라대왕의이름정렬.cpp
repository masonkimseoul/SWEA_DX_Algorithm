/*
#include <iostream>
#define MAX_N 20000

using namespace std;

void mergeSort(string ar[], int size)
{
	int mid = size / 2;
	int i = 0, j = mid, k = 0;
	if (size == 1) return;
		
	mergeSort(ar, mid);
	mergeSort(ar + mid, size - mid);

	string* buf = new string[size];
	
	while (i < mid && j < size) {
		if (ar[i].size() == ar[j].size()) {
			buf[k++] = (ar[i] < ar[j]) == true ? ar[i++] : ar[j++];
		}
		else {
			buf[k++] = ar[i].size() < ar[j].size() ? ar[i++] : ar[j++];
		}
	}

	while (i < mid) buf[k++] = ar[i++];
	
	while (j < size) buf[k++] = ar[j++];

	for (i = 0; i < size; i++) ar[i] = buf[i];

	delete[] buf;
}

int main()
{
	int T, TC, N, i;
	string s;
	cin >> T;
	for (TC = 0; TC < T; TC++)
	{
		string ar[MAX_N];
		cin >> N;
		for (i = 0; i < N; i++) {
			cin >> s;
			ar[i] = s;
		}
		mergeSort(ar, N);
		cout << "#" << TC + 1 << '\n';
		for (i = 0; i < N; i++) {
			if (ar[i] != ar[i + 1]) cout << ar[i] << '\n';
		}
	}
}
*/