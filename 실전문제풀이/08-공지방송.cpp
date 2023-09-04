/*
#include <cstring>
#include <unordered_map>
#define ll long long
#define MAX_SIZE 86501
using namespace std;
unordered_map<int, ll> broadcast;

int Time[MAX_SIZE];

void init() { broadcast.clear(); }

int add(int mId, int mStart, int mEnd) {
    int broadcastSize;
    broadcast[mId] = ((ll)mStart << 32) + 1 + mEnd;
    broadcastSize = broadcast.size();
    return broadcastSize;
}

int remove(int mId) {
    int broadcastSize;
    broadcast.erase(mId);
    broadcastSize = broadcast.size();
    return broadcastSize;
}

int announce(int mDuration, int M) {
    int start, end, pos, i;
    memset(Time, 0, sizeof(Time));

    for (auto [_, br] : broadcast) {
        start = br >> 32;
        end = br & 0xffffffff;
        if (start <= end - mDuration) {
            Time[start] += 1;
            Time[end - mDuration + 1] -= 1;
        }
    }

    pos = 0;
    for (i = 0; i < 86400; ++i) {
        pos += Time[i];
        if (pos >= M) return i;
    }
    return -1;
}
*/