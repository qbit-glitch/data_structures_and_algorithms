/**
 * GFG: Length of the Loop
 * Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1
*/

#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

Node* converArrayToLL(vector<int>& a){
    Node* head = new Node(a[0]);
    Node* temp = head;
    for(int i=1; i<a.size(); i++){
        Node* newNode = new Node(a[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void printLL(Node* head){
    while(head != nullptr){
        cout << head -> data << " " ;
        head = head->next;
    }
    cout << endl;
}

bool hasCycle(Node* head){
    if(head == NULL or head->next==NULL or head->next->next==NULL)
        return false;
    Node* step = head;
    Node* two_steps = step;
    while(two_steps!=NULL and two_steps->next != NULL){
        step = step->next;
        two_steps = two_steps->next->next;
        if(step == two_steps)
            return true;
    }
    return false;
}

Node* buildCLL(Node* head, Node* node){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return head;
}


int detectCycleHead(Node* head){
    int cnt=0;
    unordered_map<Node*, int> hashMap;
    Node* temp = head;
    int ans;
    while(temp != NULL){
        cnt++;
        // cout << temp->data << " ";
        if(hashMap.find(temp) != hashMap.end()){
            return hashMap[temp];
        }
        hashMap[temp] = cnt;
        temp = temp->next;
    }
    return -1;
}



/**
 * Modify the Tortoise and Hare algp
 * slow increase by 1 steps and fast increase by 2 steps
 * When slow and fast meets at the first time then do this:
 * make slow/fast anyone point to head
 * then move both the slow and fast increase by 1 step
 * slow and fast converges again for the 2nd time and it gives our cycle head 
*/

Node* detectCycleHead_Optimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL and fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            slow  = head;
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return NULL;
}

int lengthOfLoop(Node* head){
    Node* headOfCycle = detectCycleHead_Optimal(head);
    Node* temp = headOfCycle;
    int cnt=0;
    while(temp != NULL){
        cnt++;
        temp = temp -> next;
        if(temp == headOfCycle)
            return cnt;
    }
    return -1;
}




int main(){
    vector<int> a{4,9,10,11,12,13,14,15};
    Node* head = converArrayToLL(a);
    head = buildCLL(head, head->next->next);
    // printLL(head);
    cout << lengthOfLoop(head) << endl;
}