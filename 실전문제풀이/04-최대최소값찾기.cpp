/*
#include<algorithm>
#include<climits>
#define INF INT_MAX
#define BUCKET_MAX 448
using namespace std;

int poolLastIndex;
struct Bucket {
    int len, min_num, max_num,numbers[BUCKET_MAX], i;
    Bucket* prev, * next;

    void init(Bucket* prev_, Bucket* next_) {
        len = 0;
        prev = prev_;
        next = next_;
        min_num = INF;
        max_num = -INF;
    }
    void push_back(int num) {
        numbers[len++] = num;
        min_num = min(min_num, num);
        max_num = max(max_num, num);
    }
    void recalc() {
        min_num = INF;
        max_num = -INF;
        for (i = 0; i < len; i++) {
            min_num = min(min_num, numbers[i]);
            max_num = max(max_num, numbers[i]);
        }
    }
};
Bucket pool[500];
Bucket bucket_begin, bucket_end;

void add(int mValue_len, int mValue[]) {
    for (int i = 0; i < mValue_len; i++) {
        if (bucket_end.prev->len >= BUCKET_MAX) {
            pool[++poolLastIndex].init(bucket_end.prev, &bucket_end);
            bucket_end.prev->next = &pool[poolLastIndex];
            bucket_end.prev = &pool[poolLastIndex];
        }

        bucket_end.prev->push_back(mValue[i]);
    }
}

void init(int mValue_len, int mValue[]) {
    poolLastIndex = 0;
    pool[0].init(&bucket_begin, &bucket_end);
    bucket_begin.next = &pool[0];
    bucket_end.prev = &pool[0];

    add(mValue_len, mValue);
}

void erase(int mFrom, int mTo) {
    int skip, rest, i;
    skip = mFrom - 1;
    rest = mTo - mFrom + 1;
    Bucket* bucket = bucket_begin.next;

    while (skip >= bucket->len) {
        skip -= bucket->len;
        bucket = bucket->next;
    }
    while (rest > 0 && bucket->len - skip <= rest) {
        rest -= bucket->len - skip;
        bucket->len = skip;
        bucket->recalc();

        if (bucket->len == 0) {
            bucket->prev->next = bucket->next;
            bucket->next->prev = bucket->prev;
        }
        bucket = bucket->next;
        skip = 0;
    }
    if (rest > 0) {
        if (bucket->prev != &bucket_begin && bucket->prev->len + bucket->len - rest <= BUCKET_MAX) {
            for (i = 0; i < skip; i++) bucket->prev->push_back(bucket->numbers[i]);
            for (i = skip + rest; i < bucket->len; i++) bucket->prev->push_back(bucket->numbers[i]);
            
            bucket->prev->next = bucket->next;
            bucket->next->prev = bucket->prev;
        }
        else {
            for (i = skip + rest; i < bucket->len; i++) bucket->numbers[i - rest] = bucket->numbers[i];
            bucket->len -= rest;
            bucket->recalc();
        }
    }
}

int find(int m) {
    int min_num = INF, max_num = -INF, i;
    Bucket* bucket = bucket_end.prev;

    while (m > 0) {
        if (bucket->len >= m) {
            for (i = bucket->len - m; i < bucket->len; i++) {
                min_num = min(min_num, bucket->numbers[i]);
                max_num = max(max_num, bucket->numbers[i]);
            }
            m = 0;
        }

        else {
            min_num = min(min_num, bucket->min_num);
            max_num = max(max_num, bucket->max_num);
            m -= bucket->len;
        }

        bucket = bucket->prev;
    }
    return max_num - min_num;
}
*/