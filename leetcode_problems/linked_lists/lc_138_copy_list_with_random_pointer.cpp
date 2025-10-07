/**
 * Leetcode-138: Copy List With random pointer
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* findNodeForRandomIndex(Node* head, int k) {
    if (k == -1)
        return nullptr;
    
    Node* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        if (cnt == k)
            return temp;
        cnt++;
        temp = temp->next;
    }
    return nullptr;
}

Node* convertArrayToRPLL(vector<vector<int>> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    
    Node* head = new Node(arr[0][0]);
    Node* temp = head;
    
    for (int i = 1; i < arr.size(); i++) {
        Node* n = new Node(arr[i][0]);
        temp->next = n;
        temp = n;
    }
    
    temp = head;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].size() > 1) {
            temp->random = findNodeForRandomIndex(head, arr[i][1]);
        }
        temp = temp->next;
    }
    
    return head;
}

void printRPLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->random != nullptr) {
            cout << temp->val << " | " << temp->random->val << endl;
        } else {
            cout << temp->val << " | NULL" << endl;
        }
        temp = temp->next;
    }
}


void deleteRPLL(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}



Node* insertCopyNodesInBetween(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        Node* copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
    return head;
}

Node* connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;
        if(temp->random)
        copyNode->random = temp->random->next;
        else
        copyNode->random = nullptr;
        temp = temp->next->next;
    }
    return head;
}

Node* connectNextPointers(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    
    while(temp != NULL){
        res->next = temp->next;
        temp->next = temp->next->next;
        
        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node* copyRandomList(Node* head) {
    Node* tHead = insertCopyNodesInBetween(head);
    tHead = connectRandomPointers(tHead);
    return connectNextPointers(tHead);
}


int main() {
    vector<vector<int>> arr = {{7, 1}, {13, 1}, {11, 3}, {10, -1}};
    
    Node* head = convertArrayToRPLL(arr);
    Node* head2 = copyRandomList(head);
    printRPLL(head);
    printRPLL(head2);
    
    return 0;
}
