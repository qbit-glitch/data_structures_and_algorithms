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
            // cout << key << " found !" << endl;
            Node* node = mpp[key];
            node->val = value;

            Node* temp = deleteNode(node);
            insertAfterHead(temp, head);
        }
        else {
            if(mpp.size() == capacity){
                // cout << "Capacity Reached ... Deleting 1 node" << endl;
                Node* temp = tail->prev;
                mpp.erase(temp->key);
                
                temp = deleteNode(temp);
                delete temp;

            }

            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node, head);
            
            // printf("Capacity: %d\n", capacity);
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


int main(){

    // Your LRUCache object will be instantiated and called as such:
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);

    obj->put(1,1);
    obj->put(2,2);
    obj->put(3,3);
    int p1 = obj->get(1);
    obj->put(4,4);
    obj->put(2,9);
    obj->printCache();
}