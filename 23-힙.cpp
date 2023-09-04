/*
#include <iostream>
using namespace std;

#define MAXN 100000

int heap[MAXN];
int heapCnt;

void add(int data) {
    int pivot = heapCnt, p;
    heap[heapCnt++] = data;
    while (pivot > 0) {
        p = pivot;
        pivot--;
        pivot = pivot >> 1;
        if (heap[pivot] < data) {
            heap[p] = heap[pivot];
            heap[pivot] = data;
        }
        else return;
    }
    return;
}
int pop() {
    if (heapCnt == 0) return -1;
    int data = heap[0], pivot, p, tmp;
    heapCnt--;
    heap[0] = heap[heapCnt];
    pivot = 0;
    while (true) {
        p = pivot;
        pivot = pivot << 1;
        pivot++;
        if (pivot >= heapCnt) break;
        else if (pivot + 1 == heapCnt) {
            if (heap[p] > heap[pivot]) break;
            tmp = heap[p];
            heap[p] = heap[pivot];
            heap[pivot] = tmp;
            break;
        }
        else {
            if (heap[pivot] < heap[pivot + 1]) pivot++;
            if (heap[p] > heap[pivot]) break;
            tmp = heap[pivot];
            heap[pivot] = heap[p];
            heap[p] = tmp;
        }
    }
    return data;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, TC, N, cmd, i, number;
    cin >> T;
    for (TC = 1; TC <= T; TC++) {
        cout << '#' << TC << ' ';
        heapCnt = 0;
        cin >> N;
        for (i = 0; i < N; i++) {
            cin >> cmd;
            if (cmd == 1) {
                cin >> number;
                add(number);
            }
            else cout << pop() << ' ';
        }
        cout << '\n';
    }
}
*/
