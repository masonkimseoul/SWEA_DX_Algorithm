#define MAX_USER 100000
#define MAX_TOP 10

struct User {
    int uID, income;
};

User users[MAX_USER];
int usercnt = 0;

void swap(User& a, User& b) {
    User temp = a;
    a = b;
    b = temp;
}

bool compare(User a, User b) {
    return (a.income > b.income) || (a.income == b.income && a.uID < b.uID);
}

void partialSort(User arr[], int n, int k) {
    int i, j;
    for (i = 0; i < k; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (compare(arr[j], arr[i])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void init() {
    usercnt = 0;
}

void addUser(int uID, int income) {
    users[usercnt].uID = uID;
    users[usercnt].income = income;
    ++usercnt;
}

int getTop10(int result[MAX_TOP]) {
    partialSort(users, usercnt, MAX_TOP);

    int cnt = 0, i;
    for (i = 0; i < MAX_TOP && i < usercnt; i++) {
        result[i] = users[i].uID;
        ++cnt;
    }
    return cnt;
}
