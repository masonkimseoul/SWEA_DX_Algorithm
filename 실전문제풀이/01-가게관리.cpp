/*
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<functional>

using namespace std;

typedef struct Buy {
    int mProduct, mPrice, mQuantity, mRest;
}Buy;

typedef struct Sell {
    bool isValid;
    int mProduct;
    list<pair<int, int>>::iterator itBegin, itEnd;
}Sell;

unordered_map<int, Buy> buy_map;
unordered_map<int, int> product_map;

unordered_map<int, Sell> sell_map;
list<pair<int, int>> sell_history_list;

int lastQueueIdx;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q[601];
unordered_map <int, int> queueIdx;

void init() {
    int i;

    buy_map.clear();
    queueIdx.clear();
    sell_history_list.clear();
    product_map.clear();
    for (i = 1; i <= lastQueueIdx; i++) while (!q[i].empty()) q[i].pop();

    lastQueueIdx = 0;
}

int buy(int bId, int mProduct, int mPrice, int mQuantity) {
    buy_map[bId] = { mProduct, mPrice, mQuantity, mQuantity };
    product_map[mProduct] += mQuantity;

    if (queueIdx[mProduct] == 0) queueIdx[mProduct] = ++lastQueueIdx;

    q[queueIdx[mProduct]].push({ mPrice, bId });
    return product_map[mProduct];
}

int cancel(int bId) {
    auto iter = buy_map.find(bId);

    if (iter == buy_map.end() || iter->second.mRest != iter->second.mQuantity) return -1;

    product_map[iter->second.mProduct] -= iter->second.mRest;
    iter->second.mRest = 0;

    return product_map[iter->second.mProduct];
}

int sell(int sId, int mProduct, int mPrice, int mQuantity) {
    int index, profit, bId, count;

    if (mQuantity > product_map[mProduct]) return -1;

    product_map[mProduct] -= mQuantity;

    sell_map[sId].isValid = true;
    sell_map[sId].mProduct = mProduct;
    sell_map[sId].itEnd = sell_history_list.begin();

    index = queueIdx[mProduct];
    profit = 0;

    while (mQuantity > 0) {
        bId = q[index].top().second;
        count = min(buy_map[bId].mRest, mQuantity);
        buy_map[bId].mRest -= count;

        mQuantity -= count;
        profit += (mPrice - buy_map[bId].mPrice) * count;
        sell_history_list.push_front({ bId, count });

        if (buy_map[bId].mRest <= 0) q[index].pop();
    }
    sell_map[sId].itBegin = sell_history_list.begin();

    return profit;
}

int refund(int sId) {
    int count, index;

    if (!sell_map[sId].isValid) return -1;

    count = 0;
    index = queueIdx[sell_map[sId].mProduct];
    sell_map[sId].isValid = false;

    for (auto iter = sell_map[sId].itBegin; iter != sell_map[sId].itEnd; iter++) {
        if (buy_map[iter->first].mRest == 0) q[index].push({ buy_map[iter->first].mPrice, iter->first });
        buy_map[iter->first].mRest += iter->second;
        count += iter->second;
    }

    product_map[sell_map[sId].mProduct] += count;

    return count;
}
*/