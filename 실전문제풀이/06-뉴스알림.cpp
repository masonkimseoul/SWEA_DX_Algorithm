/*
#include<vector>
#include<queue>
#include<unordered_map>
#define USER_SIZE_MAX 500
#define CHANNEL_SIZE_MAX 500
#define NEWS_SIZE_MAX 30000
using namespace std;

unordered_map< int, int > user_info;
unordered_map< int, int > channel_info;
unordered_map< int, int > news_info;

typedef struct NEWS {
	int time, news_id, channel_id;
	bool isCanceled;
	bool operator() (NEWS* a, NEWS* b) {
		if (a->time == b->time)	return a->news_id > b->news_id;
		return a->time > b->time;
	}
}NEWS;

priority_queue<NEWS*, vector<NEWS*>, NEWS> news_queue;

NEWS news_pool[NEWS_SIZE_MAX];
vector<int> channel_pool[CHANNEL_SIZE_MAX];
vector<NEWS*> user_pool[USER_SIZE_MAX];

int news_index, channel_index, user_index;

void init(int N, int K)
{
	news_queue = {};
	user_info.clear();
	channel_info.clear();
	news_info.clear();
	
	news_index = 0;
	channel_index = 0;
	user_index = 0;
}

void updateNews(int mTime)
{
	int i;
	NEWS* now_news;
	
	while (!news_queue.empty()) {
		now_news = news_queue.top();
		if (now_news->time > mTime) return;
		news_queue.pop();

		if (now_news->isCanceled) continue;
		for (i = 0; i < channel_pool[now_news->channel_id].size(); i++) user_pool[channel_pool[now_news->channel_id][i]].push_back(now_news);
	}
}

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[]) {
	int user_index_pos, channel_index_pos, i;
	updateNews(mTime);
	if (user_info.find(mUID) == user_info.end()) {
		user_index_pos = user_info[mUID] = user_index++;
		user_pool[user_index_pos].clear();
	}
	else user_index_pos = user_info[mUID];

	for (i = 0; i < mNum; i++) {
		if (channel_info.find(mChannelIDs[i]) == channel_info.end()) {
			channel_index_pos = channel_info[mChannelIDs[i]] = channel_index++;
			channel_pool[channel_index_pos].clear();
		}
		else channel_index_pos = channel_info[mChannelIDs[i]];
		channel_pool[channel_index_pos].push_back(user_index_pos);
	}
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID) {
	int channel_index_pos, news_index_pos;
	channel_index_pos = channel_info[mChannelID];
	news_index_pos = news_info[mNewsID] = news_index++;
	news_pool[news_index_pos] = { mTime + mDelay, mNewsID, channel_index_pos, false };
	news_queue.push(&news_pool[news_index_pos]);

	return channel_pool[channel_index_pos].size();
}

void cancelNews(int mTime, int mNewsID) {
	news_pool[news_info[mNewsID]].isCanceled = true;
}

int checkUser(int mTime, int mUID, int mRetIDs[]) {
	int i, user_index_pos, result, cnt;
	
	updateNews(mTime);
	user_index_pos = user_info[mUID];
	result = user_pool[user_index_pos].size();
	cnt = 0;
	for (i = user_pool[user_index_pos].size() - 1; i >= 0; i--) {
		if (user_pool[user_index_pos][i]->isCanceled) result--;
		else if (cnt < 3) mRetIDs[cnt++] = user_pool[user_index_pos][i]->news_id;
	}
	user_pool[user_index_pos].clear();

	return result;
}
*/