/**
 * Leetcode-460: LFU Cache
 * Link: https://leetcode.com/problems/lfu-cache/description/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key, val;
    Node* next;
    Node* prev;

    Node(int key1, int val1){
        key = key1;
        val = val1;
        prev = nullptr;
        next = nullptr;
    }
};

void deleteNode(Node* node){
    Node* nextNode = node->next;
    Node* prevNode = node->prev;

    nextNode->prev = prevNode;
    prevNode->next = nextNode;
}

void insertAfterHead(Node* node, Node* head){
    Node* nodeAfterHead = head->next;
    head->next = node;
    node->prev = head;

    node->next = nodeAfterHead;
    nodeAfterHead->prev = node;
}


class LFUCache {

private:
    unordered_map<int, pair<Node*, int>> mpp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int capacity;

public:
    LFUCache(int capacity1) {
        capacity = capacity1;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())
            return -1;

        pair<Node*, int> nodeWithCount = mpp[key];
        Node* node = nodeWithCount.first;
        
        deleteNode(node);
        insertAfterHead(node, head);

        nodeWithCount.second++;

        return nodeWithCount.first->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            pair<Node*, int> nodeWithCount = mpp[key];
            
            deleteNode(nodeWithCount.first);
            nodeWithCount.first->val = value;
            insertAfterHead(nodeWithCount.first, head);

            nodeWithCount.second++;
        }
        else {
            
        }
    }
};