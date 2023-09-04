/*
#include<iostream>
using namespace std;

typedef struct node {
	int elem;
	struct node* next;
}node;

node nodePool[10000], * head;
int nodePoolCnt;

node* getNode(int data) {
	nodePool[nodePoolCnt].elem = data;
	nodePool[nodePoolCnt].next = nullptr;

	return &nodePool[nodePoolCnt++];
}
*/

