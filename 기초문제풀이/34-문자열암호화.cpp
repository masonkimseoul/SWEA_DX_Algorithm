#define MAX_N 50005
#define HASH_SIZE (1<<15)

struct node {
    int idx;
    node* next;
    node* prev;

    node* Alloc(int _idx, node* _prev, node* _next) {
        idx = _idx;
        prev = _prev;
        next = _next;
        if (_next) _next->prev = this;
        if (_prev) _prev->next = this;

        return this;
    }
} nodes[MAX_N];

char str[MAX_N];
int N;
node hashTable[HASH_SIZE];

int getHash(char* A) {
    int hash = *A++ - 'a';
    hash = (hash << 5) + *A++ - 'a';
    hash = (hash << 5) + *A - 'a';
    return hash;
}

int getNext(int hash, char* A) {
    hash &= (1 << 10) - 1;
    hash = (hash << 5) + *(A + 3) - 'a';

    return hash;
}

int getPrev(int hash, char* A) {
    hash = hash >> 5;
    hash += (*A - 'a') << 10;

    return hash;
}

void mstrcpy(char* dst, char* src) {
    while (*src) *dst++ = *src++;
    *dst = 0;
    return;
}

void InputHash(node* tmp, int hash) {
    node* pivot = &hashTable[hash];
    while (pivot->next) {
        if (pivot->next->idx > tmp->idx) break;
        pivot = pivot->next;
    }
    tmp->next = pivot->next;
    pivot->next = tmp;
    tmp->prev = pivot;
    if (tmp->next) tmp->next->prev = tmp;

    return;
}

void init(int _N, char init_string[]) {
    N = _N;
    mstrcpy(str, init_string);
    for (int i = 0; i < HASH_SIZE; i++) hashTable[i].Alloc(-1, nullptr, nullptr);
    int hash = getHash(init_string + N - 3);
    hashTable[hash].next = nodes[N - 3].Alloc(N - 3, &hashTable[hash], hashTable[hash].next);
    for (int i = N - 4; i >= 0; i--) {
        hash = getPrev(hash, &init_string[i]);
        hashTable[hash].next = nodes[i].Alloc(i, &hashTable[hash], hashTable[hash].next);
    }

    return;
}

int change(char A[], char B[]) {

    int hashA = getHash(A);

    node* pivot = hashTable[hashA].next;
    hashTable[hashA].next = nullptr;
    int prevIdx = -3;

    int cnt = 0;
    while (pivot) {
        pivot->prev = nullptr;
        if (prevIdx + 3 > pivot->idx) {
            node* tmp = pivot->next;
            InputHash(pivot, hashA);
            pivot = tmp;
            continue;
        }
        cnt++;
        prevIdx = pivot->idx;
        str[pivot->idx] = B[0];
        str[pivot->idx + 1] = B[1];
        str[pivot->idx + 2] = B[2];
        node* tmp = pivot->next;
        while (tmp && prevIdx + 3 > tmp->idx) {
            tmp = tmp->next;
        }
        int hash = -1;
        for (int i = pivot->idx - 2; i <= pivot->idx + 2; i++) {
            if (i < 0) continue;
            else if (i == N - 2) break;
            if (hash == -1) hash = getHash(str + i);
            else hash = getNext(hash, str + i - 1);

            if (nodes[i].prev) nodes[i].prev->next = nodes[i].next;
            if (nodes[i].next) nodes[i].next->prev = nodes[i].prev;
            node* aa = &hashTable[33];

            InputHash(nodes + i, hash);
        }
        pivot = tmp;
    }

    return cnt;
}

void result(char ret[]) {
    mstrcpy(ret, str);
    return;
}
