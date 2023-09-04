/*
#include<iostream>
#include<cstring>
#define MAX_SIZE 4000000
using namespace std;

struct Result {
    int top;
    int count;
};

int segment_min[MAX_SIZE], segment_max[MAX_SIZE], lazy[MAX_SIZE], MOD = MAX_SIZE / 4, c, cnt = 0;

void busy(int N, int left, int right) {
    if (lazy[N] == 0) return;
    segment_max[N] += lazy[N];
    segment_min[N] += lazy[N];
    if (right != left) {
        lazy[N * 2 + 1] += lazy[N];
        lazy[N * 2] += lazy[N];
    }
    
    lazy[N] = 0;
}

void Add(int N, int left, int right, int start, int end, int D) {
    int mid;
    busy(N, left, right);
    if (end < left || right < start) return;
    if (start <= left && right <= end) {
        lazy[N] += D;
        busy(N, left, right);
        return;
    }
    mid = (left + right) / 2;
    Add(N * 2, left, mid, start, end, D);
    Add(N * 2 + 1, mid + 1, right, start, end, D);
    segment_min[N] = min(segment_min[N * 2], segment_min[N * 2 + 1]);
    segment_max[N] = max(segment_max[N * 2], segment_max[N * 2 + 1]);
}

int get_max() {
    busy(1, 0, c - 1);
    return segment_max[1];
}

int get_min() {
    busy(1, 0, c - 1);
    return segment_min[1];
}

void init(int C) {
    c = C;
    cnt = 0;
    memset(lazy, 0, c * 16);
    memset(segment_max, 0, c * 16);
    memset(segment_min, 0, c * 16);
}

Result dropBlocks(int mCol, int mHeight, int mLength) {
    Result answer;
    int minimum;
    Add(1, 0, c - 1, mCol, mCol + mLength - 1, mHeight);
    minimum = get_min();
    cnt = ((cnt + mHeight * mLength - minimum * c) % MOD + MOD) % MOD;
    Add(1, 0, c - 1, 0, c - 1, -minimum);

    answer.count = cnt;
    answer.top = get_max();
    
    return answer;
}
*/