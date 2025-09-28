/**
 * GFG: Insert Element at Kth Position in Linked List
 * Link: https://www.geeksforgeeks.org/problems/insertion-at-a-given-position-in-a-linked-list/1
*/


class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node *insertPos(Node *head, int pos, int val) {
    // code here
    if(head == nullptr){
        if(pos == 1){
            return new Node(val);
        }
        else return nullptr;
    }
    if(pos == 1){
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        cnt++;
        if(cnt == pos-1){
            Node* newNode = new Node(val);
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
        temp = temp->next;
    }
    return head;
}