/*
#include <iostream>
#define ull unsigned long long
using namespace std;

ull fpow(ull N, ull sum) {
	if (N == 0) return 1;
	ull result = fpow(N / 2, sum);
	result = (result * result) % sum;

	if (N & 1) result = (result * 2) % sum;
	return result;
}

ull find(ull a, ull b, ull k) {
	ull sum = a + b;
	ull result = (fpow(k, sum) * a) % sum;
	return min(result, sum - result);
}

int main()
{
	int T, TC;
	ull a, b, k;
	cin >> T;
	for (TC = 0; TC < T; TC++) {
		cin >> a >> b >> k;
		find(a, b, k);
		cout << "#" << TC + 1 << " " << find(a, b, k) << "\n";
	}
}
*/