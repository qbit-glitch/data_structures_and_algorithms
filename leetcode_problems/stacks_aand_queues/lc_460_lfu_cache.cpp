/**
 * Leetcode-460: LFU Cache
 * Link: https://leetcode.com/problems/lfu-cache/description/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key, val, cnt;
    Node* prev;
    Node* next;

    Node(int _key, int _val){
        key = _key;
        val = _val;
        cnt = 1;
        prev = nullptr;
        next = nullptr;
    }
};

struct List{
    Node* head;
    Node* tail;
    int size;

    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head ->next = tail;
        tail->prev = head;

        size = 0;
    }

    void addFront(Node* node){
        Node* nodeAfterHead = head->next;
        head->next = node;
        node->prev = head;

        node->next = nodeAfterHead;
        nodeAfterHead->prev = node;
        
        size++;
    }

    void deleteNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        size--;
    }
};

class LFUCache{
    unordered_map<int, List*> freqListMap;
    unordered_map<int, Node*> keyNode;

    int maxCacheSize, curSize, minFreq;

    public:
    LFUCache(int capacity){
        maxCacheSize = capacity;
        curSize=0;
        minFreq = 0;
    }

    void updateListFreq(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);

        if(node->cnt == minFreq and freqListMap[node->cnt]->size == 0)
            minFreq++;

        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end())
            nextHigherFreqList = freqListMap[node->cnt+1];

        node->cnt += 1;
        nextHigherFreqList->addFront(node);

        keyNode[node->key] = node;
        freqListMap[node->cnt] = nextHigherFreqList;
    }

    int get(int key){
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            updateListFreq(node);

            return node->val;
        }
        return -1;
    }

    void put(int key, int value){
        if(maxCacheSize == 0)
            return;
        
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;

            updateListFreq(node);
        }
        else {
            if(maxCacheSize == curSize){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end())
                listFreq = freqListMap[minFreq];
            
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

int main(){
    int capacity = 2;
    LFUCache* obj = new LFUCache(capacity);
    
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl;

    obj->put(3,3);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;

    obj->put(4,4);
    cout << obj->get(1) << endl;
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;

}