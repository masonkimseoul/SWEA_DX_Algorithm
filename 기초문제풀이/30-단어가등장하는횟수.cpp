#include <iostream>
using namespace std;

#define MAX_B 500001
#define MAX_S 100001

char B[MAX_B], S[MAX_S];
int P[MAX_S];

void CalcP() {
    int i, j;

    P[0] = 0;
    for (i = 1; S[i]; i++) {
        j = P[i - 1];

        while (j > 0) {
            if (S[i] == S[j]) break;
            j = P[j - 1];
        }

        if (S[i] == S[j]) P[i] = j + 1;
        else P[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, TC, pos, cnt, ans;
    cin >> T;
    for (TC = 0; TC < T; TC++) {
        cin >> B >> S;
        CalcP();
        pos = 0, cnt = 0, ans = 0;

        while (B[pos]) {
            if (B[pos] == S[cnt]) {

                if (!S[cnt + 1]) {
                    ans++;
                    cnt = P[cnt];
                }
                else cnt++;

                pos++;
            }
            else if (cnt > 0) cnt = P[cnt - 1];
            else pos++;
        }

        cout << '#' << TC + 1 << ' ' << ans << '\n';
    }
}
