/*
#include <iostream>
using namespace std;

#define MAX_N 2000
#define MAX_HASH (1 << 30)
#define DIV (MAX_HASH - 1)
#define ull unsigned long long

int myPic[MAX_N][MAX_N], samPic[MAX_N][MAX_N], samHash[MAX_N][MAX_N], tmp[MAX_N][MAX_N];
int H, W, N, M;

int CalcMul(int num, int shift) {
    int i;
    ull rev = 1;
    for (i = 1; i < num; i++) rev = (rev << shift) + rev;
    return (int)(rev & DIV);
}

int GetHash(int* piv, int num, int shift) {
    int i;
    ull hash = 0;
    for (i = 0; i < num; i++) hash = (hash << shift) + hash + *piv++;
    return (int)(hash & DIV);
}

int GetNext(int prev, int sub, int mul, int add, int shift) {
    ull hash = prev - (sub * mul);
    hash = (hash << shift) + hash + add;
    return (int)(hash & DIV);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, TC, i, j, cnt;
    int h, w, n, m, myHash, mulC, mulR;
    char a;

    cin >> T;
    for (TC = 0; TC < T; TC++) {
        cin >> H >> W >> N >> M;
        for (h = 0; h < H; h++){
            for (w = 0; w < W; w++) {            
                cin >> a;
                if (a == 'o') myPic[h][w] = 1;
                else myPic[h][w] = 0;
            }
        }
        for (n = 0; n < N; n++) {
            for (m = 0; m < M; m++) {
                cin >> a;
                if (a == 'o') samPic[n][m] = 1;
                else samPic[n][m] = 0;
            }
        }

        for (i = 0; i < H; i++) tmp[0][i] = GetHash(myPic[i], W, 4);
        myHash = GetHash(tmp[0], H, 5);

        mulC = CalcMul(W, 4);
        mulR = CalcMul(H, 5);
        for (i = 0; i < N; i++) {
            tmp[0][i] = GetHash(samPic[i], W, 4);
            for (j = 1; j < M - W + 1; j++) {
                tmp[j][i] = GetNext(tmp[j - 1][i], samPic[i][j - 1], mulC, samPic[i][j + W - 1], 4);
            }
        }
        for (i = 0; i < M - W + 1; i++) {
            samHash[0][i] = GetHash(tmp[i], H, 5);
            for (j = 1; j < N - H + 1; j++) {
                samHash[j][i] = GetNext(samHash[j - 1][i], tmp[i][j - 1], mulR, tmp[i][j + H - 1], 5);
            }
        }

        cnt = 0;
        for (i = 0; i < N - H + 1; i++) {
            for (j = 0; j < M - W + 1; j++)
                if (samHash[i][j] == myHash) cnt++;
        }
        cout << '#' << TC + 1 << ' ' << cnt << '\n';
    }
}
*/