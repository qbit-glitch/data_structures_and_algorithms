/**
 * Leetcode-146: LRU Cache
 * Link: https://leetcode.com/problems/lru-cache/description/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key, val;
    Node* prev;
    Node* next;

    Node(int key1, int val1){
        key = key1;
        val = val1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* deleteNode(Node* node){
    Node* prevNode = node->prev;
    Node* nextNode = node->next;
    
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    return node;
}

void insertAfterHead(Node* node, Node* head){
    Node* nodeAfterHead = head->next;
    head->next = node;
    node->prev  = head;

    nodeAfterHead->prev = node;
    node->next = nodeAfterHead;
}


void printHashMap(unordered_map<int, Node*> mpp){
    for(auto &i: mpp){
        cout << i.first  << " ";
    }
    cout << endl;
}

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
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())
            return -1;
        Node* node = mpp[key];
        
        Node* temp = deleteNode(node);
        insertAfterHead(temp, head);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;

            Node* temp = deleteNode(node);
            insertAfterHead(temp, head);
        }
        else {
            if(mpp.size() == capacity){
                Node* temp = tail->prev;
                mpp.erase(temp->key);
                
                temp = deleteNode(temp);
                delete temp;
                
                capacity--;
            }

            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node, head);
            capacity++;
        }
        printHashMap(mpp);
    }

    void printCache(){
        for(auto &i: mpp){
            Node* node = i.second;
            cout << node->key << "," << node->val << endl;
        }
    }
};


int main(){

    // Your LRUCache object will be instantiated and called as such:
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);
    int param_1 = obj->get(2);
    obj->put(1,1);
    obj->put(2,2);
    // cout << obj->get(1) << endl;
    obj->put(3,3);
    // cout << obj->get(2) << endl;
    // obj->printCache();
}