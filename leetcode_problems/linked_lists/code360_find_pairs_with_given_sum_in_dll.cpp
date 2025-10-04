/**
 * Code360: Find Pairs with given Sum in DLL
 * Link: https://www.naukri.com/code360/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172

 * GFG Link: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convertArrayToDLL(vector<int> &a){
    if(a.size() == 0)
        return nullptr;
    Node* head = new Node(a[0]);
    Node* temp = head;

    for(int i=1; i<a.size(); i++){
        Node* n = new Node(a[i], nullptr, temp);
        temp->next = n;
        temp = temp->next;
    }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* getEndNodeOfList(Node* head){
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    Node* p1 = head;
    Node* p2 = getEndNodeOfList(head);
    vector<pair<int,int>> result;
    int cnt=0;
    
    while(p1 != NULL and p2!=NULL and p1 != p2 and p1 != p2->next){
        int sum = p1->data + p2->data;
        
        if(sum == k){
            result.push_back(make_pair(p1->data, p2->data));
            cnt++;
            p1 = p1->next;
            p2 = p2->prev;
        }
        else if(sum > k){
            p2 = p2->prev;
        }
        else    p1 = p1->next;
    }
    return result;
}


void printVectorsOfPairs(vector<pair<int,int>> &r){
    for(auto &i: r){
        cout << i.first << " " << i.second << endl;
    }
}



int main(){
    vector<int> a{3,4,10,15,16,18,22,25,26,28,29,31,32,33,36,38,40,47,48,50};
    Node* head = convertArrayToDLL(a);
    printDLL(head);
    vector<pair<int,int>> result = findPairs(head, 34);

    printVectorsOfPairs(result);
}