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

class LRUCache {
private:
    int capacity;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> mpp;

public:
    LRUCache(int capacity1) {
        capacity = capacity1;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }

    
    void deleteNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

    void insertAfterHead(Node* node){
        Node* nodeAfterHead = head->next;
        head->next = node;
        node->prev = head;

        node->next = nodeAfterHead;
        nodeAfterHead->prev = node;
    }

    int get(int key) {
        if(mpp.find(key) == mpp.end())
            return -1;
        Node* node = mpp[key];
        
        deleteNode(node);
        insertAfterHead(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;

            deleteNode(node);
            insertAfterHead(node);
        }
        else {
            if(mpp.size() == capacity){
                Node* temp = tail->prev;
                mpp.erase(temp->key);
                
                deleteNode(temp);
                delete temp;

            }

            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
            
        }
        
    }

    void printCache(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->key << "," << temp->val << "   ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class LFUCache {
private:
    unordered_map<int, LRUCache> freqListCache;
    unordered_map<int, Node*> keyNode;
    unordered_map<Node*, int> freqCnt;
    int minFreq, capacity;

public:
    LFUCache(int capacity1) {
        capacity = capacity1;
        freqListCache.clear();
        keyNode.clear();        
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end())
            return -1;
        Node* node = keyNode[key];
        int freq = freqCnt[node];
        
        freqListCache[freq].deleteNode(node);
        
        freq++;
        freqListCache[freq].insertAfterHead(node);
        freqCnt[node] = freq;

        return node->val;
    }
    
    void put(int key, int value) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;

            freqListCache[freqCnt[node]++].deleteNode(node);
            freqListCache[freqCnt[node]].insertAfterHead(node);            
        }
        else {
            if(keyNode.size() == capacity){
                
            }
        }
    }
};
