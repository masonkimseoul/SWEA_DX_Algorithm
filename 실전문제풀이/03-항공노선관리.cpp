/*
#include<iostream>
#include <climits>
using namespace std;

int n, graph_Time[66][30300][3], graph_Time_Size[66], graph_Price[66][66], distance_a[66][2], distance_b[66];

struct heap {
    int size = 0;
    int data[60000][3];

    int compare(int a, int b) {
        if (data[a][0] == data[b][0]) {
            if (data[a][1] == data[b][1]) return data[a][2] < data[b][2];
            return data[a][1] < data[b][1];
        }
        return data[a][0] < data[b][0];
    }

    void swap(int a, int b) {
        int tmp[3];

        tmp[0] = data[a][0];
        tmp[1] = data[a][1];
        tmp[2] = data[a][2];

        data[a][0] = data[b][0];
        data[a][1] = data[b][1];
        data[a][2] = data[b][2];

        data[b][0] = tmp[0];
        data[b][1] = tmp[1];
        data[b][2] = tmp[2];
    }

    void push(int x, int y, int z) {
        int pos, parent;

        data[size][0] = x;
        data[size][1] = y;
        data[size][2] = z;
        size++;

        pos = size - 1;
        while (pos > 0) {
            parent = (pos - 1) / 2;
            if (compare(pos, parent)) {
                swap(pos, parent);
                pos = parent;
            }
            else break;
        }
    }

    void pop() {
        int pos, child;
        size--;
        data[0][0] = data[size][0];
        data[0][1] = data[size][1];
        data[0][2] = data[size][2];
        pos = 0;
        while (pos * 2 + 1 < size) {
            child = pos * 2 + 1;
            if (child + 1 < size && compare(child + 1, child)) child++;
            if (compare(child, pos)) {
                swap(child, pos);
                pos = child;
            }
            else break;
        }
    }

    int* top() { return data[0]; }

    int empty() { return size == 0; }

    void clear() { size = 0; }
} pq;

void init(int N) {
    int i, j;
    n = N;
    for (i = 0; i < N; i++) graph_Time_Size[i] = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) graph_Price[i][j] = INT_MAX;
    }
}

void add(int mStartAirport, int mEndAirport, int mStartTime, int mTravelTime, int mPrice) {
    int size = graph_Time_Size[mStartAirport];
    graph_Time[mStartAirport][size][0] = mEndAirport;
    graph_Time[mStartAirport][size][1] = mStartTime;
    graph_Time[mStartAirport][size][2] = mTravelTime;
    graph_Time_Size[mStartAirport]++;

    if (graph_Price[mStartAirport][mEndAirport] > mPrice) graph_Price[mStartAirport][mEndAirport] = mPrice;
}

int minTravelTime(int mStartAirport, int mEndAirport, int mStartTime) {
    int i, nextDate, nextTime;

    pq.push(0, mStartTime, mStartAirport);
    for (i = 0; i < n; i++) {
        distance_a[i][0] = INT_MAX;
        distance_a[i][1] = INT_MAX;
    }
    distance_a[mStartAirport][0] = 0;
    distance_a[mStartAirport][1] = mStartTime;
    while (!pq.empty()) {
        int pos[3] = { pq.top()[0], pq.top()[1], pq.top()[2] };
        pq.pop();
        if (pos[0] != distance_a[pos[2]][0] || pos[1] != distance_a[pos[2]][1]) continue;
        if (pos[2] == mEndAirport) {
            pq.clear();
            return pos[0] * 24 + pos[1] - mStartTime;
        }
        for (i = 0; i < graph_Time_Size[pos[2]]; i++) {
            auto next = graph_Time[pos[2]][i];
            
            nextDate = pos[0];
            if (pos[1] > next[1]) nextDate++;

            nextTime = next[1] + next[2];
            if (nextTime >= 24) {
                nextTime -= 24;
                nextDate++;
            }

            if (nextDate < distance_a[next[0]][0] || (nextDate == distance_a[next[0]][0] && nextTime < distance_a[next[0]][1])) {
                distance_a[next[0]][0] = nextDate;
                distance_a[next[0]][1] = nextTime;
                pq.push(nextDate, nextTime, next[0]);
            }
        }
    }
    return -1;
}

int minPrice(int mStartAirport, int mEndAirport) {
    int i;
    
    pq.push(0, mStartAirport, 0);
    for (i = 0; i < n; i++) distance_b[i] = INT_MAX;
    distance_b[mStartAirport] = 0;
    while (!pq.empty()) {
        int pos[2] = { pq.top()[0], pq.top()[1] };
        pq.pop();
        if (pos[0] != distance_b[pos[1]]) continue;
        if (pos[1] == mEndAirport) {
            pq.clear();
            return pos[0];
        }
        for (i = 0; i < n; i++) {
            if (graph_Price[pos[1]][i] == INT_MAX) continue;
            if (pos[0] + graph_Price[pos[1]][i] < distance_b[i]) {
                distance_b[i] = pos[0] + graph_Price[pos[1]][i];
                pq.push(pos[0] + graph_Price[pos[1]][i], i, 0);
            }
        }
    }

    return -1;
}
*/