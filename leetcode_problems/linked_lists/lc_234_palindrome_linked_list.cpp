/**
 * Leetcode-234: Palindrome Linked List
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

bool isPalindrome_Queue(Node* head){
    queue<int> que;
    Node* temp = head;
    Node* back = nullptr;
    int cnt = 0;
    while(temp != NULL){
        que.emplace(temp->data);
        Node* front = temp->next;
        temp->next = back;
        back = temp;
        temp = front;
        cnt++;
    }
    head = back;
    int c = 0;
    temp = head;
    while(temp != NULL){
        if( temp->data == que.front())
            c++;
        que.pop();
        temp = temp-> next;
    }


    return (cnt == c) ? true : false;
}


/**
 * Store elements in stack during the first pass
 * then again do the pass by comparing the temp->data with the stack top values
 */
bool isPalindrome_Stack(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(st.top() != temp->data)
            return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}


/** Perform 3 steps for the solution
 * 1. Find the middle element using the Tortoise and Hare algo 
 *      and stop when either fast->next=NULL or fast->next->next = NULL
 * 2. slow stands at the first middle element.
 *      reverse the second half using reverse(slow->next) and store the newHead
 * 3. Compare the first half and the  2nd list element by element.
 * 4. make sure the reverse the second half again to ensure
 *      that the linked list is not changed.
*/


Node* reverseList(Node* head){
    Node* temp = head;
    Node* back = nullptr;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = back;
        back = temp;
        temp = front;
    }
    return back;
}

bool isPalindrome_Optimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL and fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseList(slow->next);
    Node* first = head;
    Node* second = newHead;
    bool ans = true;
    while(second != NULL){
        if(first->data != second->data)
        {
            ans = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    slow->next = reverseList(newHead); 
    return ans;   
}


int main(){
    vector<int> a{1,2,1,1,1};
    Node* head = converArrayToLL(a);
    // printLL(head);
    cout << isPalindrome_Optimal(head) << endl;
    printLL(head);
}