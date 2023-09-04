#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct Post {
    int pID;
    int timestamp;
    int likes;

    Post(int p, int t, int l) : pID(p), timestamp(t), likes(l) {}
};

bool operator<(const Post& a, const Post& b) {
    bool within1000_a = a.timestamp >= 1000;
    bool within1000_b = b.timestamp >= 1000;

    if (within1000_a && within1000_b) {
        if (a.likes == b.likes) return a.timestamp < b.timestamp;
        return a.likes < b.likes;
    }
    else if (within1000_a) return false;
    else if (within1000_b) return true;
    else return a.timestamp < b.timestamp;
}

unordered_map<int, std::unordered_map<int, bool>> follows;
unordered_map<int, std::vector<Post>> userPosts;
unordered_map<int, Post> allPosts;

void init(int N) {
    follows.clear();
    userPosts.clear();
    allPosts.clear();
}

void follow(int uID1, int uID2, int timestamp) {
    follows[uID1][uID2] = true;
}

void makePost(int uID, int pID, int timestamp) {
    Post newPost(pID, timestamp, 0);
    userPosts[uID].push_back(newPost);
    allPosts[pID] = newPost;
}

void like(int pID, int timestamp) {
    allPosts[pID].likes++;
}

void getFeed(int uID, int currentTimestamp, int pIDList[]) {
    priority_queue<Post> feed;

    if (follows.find(uID) != follows.end()) {
        for (const auto& followee : follows[uID]) {
            if (followee.second && userPosts.find(followee.first) != userPosts.end()) {
                for (const auto& post : userPosts[followee.first]) {
                    feed.push(Post(post.pID, currentTimestamp - post.timestamp, post.likes));
                }
            }
        }
    }

    int count = 0;
    while (!feed.empty() && count < 10) {
        pIDList[count++] = feed.top().pID;
        feed.pop();
    }

    while (count < 10) pIDList[count++] = 0;
}
