/**
 * Leetcode-160: Intersection of 2 linked lists
*/

#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

void printLL(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArrayToLL(vector<int>& a){
    if(a.size() == 0)
        return nullptr;
    Node* head = new Node(a[0]);
    Node* temp = head;
    for(int i=1; i<a.size(); i++){
        Node* node = new Node(a[i]);
        temp->next = node;
        temp = node;
    }
    return head;
}

int calculateLength(Node* head){
    Node* temp = head;
    int cnt=0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}


pair<Node*, pair<int,int>> determineLongerList(Node* headA, Node* headB){
    int cntA = calculateLength(headA);
    int cntB = calculateLength(headB);
    if(cntA >= cntB)
        return make_pair(headA, make_pair(cntA, cntB));
    else 
        return make_pair(headB, make_pair(cntB, cntA));
}




Node* getIntersectionNode(Node* headA, Node* headB){
    auto longerListWithLengths = determineLongerList(headA, headB);
    Node* longerList = longerListWithLengths.first;
    Node* hA;
    Node* hB;
    
    if(longerList == headA)
    {
        hA = longerList;
        hB = headB;       
    }
    if(longerList == headB){
        hA = longerList;
        hB = headA;
    }
    int diff = longerListWithLengths.second.first - longerListWithLengths.second.second;
    
    Node* tempA = hA;
    
    int cnt = 0;
    while(tempA!=NULL){
        tempA = tempA->next;
        cnt++;
        if(cnt == diff)
            break;
    }

    Node* tempB = hB;

    while(tempA != NULL and tempB != NULL){
        if(tempA == tempB){
            return tempA;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return nullptr;

}

/** Naive Solution:
 * 1. Use Hashing to store the node along with an integer to indicate 
 *      whether visited 
 * 2. Traverse through the first list and store the nodes in memory
 * 3. Traverse through the second list and check whether any node from 
 *      the first is stored in the hashmap. If found return that node. 
 */
Node* getIntersectionNode_BruteForce(Node* headA, Node* headB){
    Node* temp = headA;
    unordered_map<Node*, int> hmap;
    while(temp != NULL){
        hmap[temp] = 1;
        temp = temp->next;
    }

    temp = headB;
    while(temp != NULL){
        if(hmap.find(temp) != hmap.end())
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

/** Optimal Approach
 * 1. Traverse through both nodes simultaneously.
 * 2. If any one node reaches null then point that node to the head of the other node and continue traversal
 * 3. When the pointer to the longer node reaches null and being sent to the head of the shorter node, 
 *      - both the pointers reach the same distance from the intersecting nodes
*/

Node* getIntersectionNode_Optimal(Node* headA, Node* headB){
    Node* t1 = headA;
    Node* t2 = headB;
    while(t1 != t2){
        if(t1 == NULL)
        {    
            t1 = headB;
            t2 = t2->next;
            continue;
        }
        if(t2 == NULL)
        {
            t2 = headA;
            t1 = t1->next;
            continue;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}




Node* joinList(Node* headA, Node* headB){
    Node* temp = headA;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = headB;
    return headA;
}



int main(){
    vector<int> common{};
    vector<int> a{1,2,3};
    vector<int> b{7,8,9,0,10,11,12};

    Node* headCommon = convertArrayToLL(common);
    Node* headA = convertArrayToLL(a);
    Node* headB = convertArrayToLL(b);

    headA = joinList(headA, headCommon);
    headB = joinList(headB, headCommon);


    Node* com = getIntersectionNode_Optimal(headA, headB);
    printLL(com);
}