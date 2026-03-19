/**
 * Array Representation of Binary Tree in C++
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


template <typename T>

struct BinaryTree {
    vector<optional<T>> data;
    int size;

    BinaryTree(int capacity) {
        data.resize(capacity+1);
        size = 0;
    }

    int insert(T value) {
        size += 1;
        data[size] = value;
        return size;
    }

    int getSize() {
        return size;
    }

    int deleteNode(int idx) {
        data[idx] = data[size];
        data.erase(data.begin() + size);
        size--;
        return size;
    }

    int search(T value) {
        for(int i=1; i<=size; i++){
            if(data[i] == value)
                return i;
        }   
        return -1;
    }

    void preOrder(vector<T> &res, int idx) {        
        if(idx > size or !data[idx].has_value()) {
            return;
        }
        res.push_back(data[idx].value());
        preOrder(res, 2*idx);
        preOrder(res, 2*idx+1);
    }


    void inOrder(vector<T> &res, int idx) {
        if(idx > size or !data[idx].has_value()) {
            return;
        }
        inOrder(res, 2*idx);
        res.push_back(data[idx].value());
        inOrder(res, 2*idx+1);
    }


    void postOrder(vector<T> &res, int idx) {
        
        if(idx > size or !data[idx].has_value()) {
            return;
        }
        
        postOrder(res, 2*idx);
        postOrder(res, 2*idx+1);

        res.push_back(data[idx].value());
    }


    /** Pre-Order Iterative
     * - push root onto the stack
     * - while stack is not empty: pop, visit, then push right first, then left
     * - stack is LIFO
     */
    vector<T> preOrderIterative(int idx){
        vector<T> res;
        stack<pair<T, int>> st;
        
        st.push({data[idx].value(), idx});
                
        
        while(!st.empty()){
            
            auto item = st.top();
            res.push_back(item.first);
            st.pop();

            int child_idx = 2 * item.second;
            if(child_idx+1 <= size and  data[child_idx + 1].has_value())
                st.push({data[child_idx + 1].value(), child_idx+1});
            if(child_idx <= size and data[child_idx].has_value())
                st.push({data[child_idx].value(), child_idx});
        }
        return res;
    }

    /** InOrder Traversal
     * - phase-1 : go to left as far as possible
     * - phase-2 : backtrack: pop, visit, move to right node and then repeat from phase 1
    */
    vector<T> inOrderIterative(int idx){
        vector<T> res;
        stack<int> st;

        int curr = idx;

        while(curr <= size || !st.empty()){
            // push left as far as possible
            while(curr <= size and data[curr].has_value()){
                st.push(curr);
                curr *= 2;
            }

            curr = st.top(); st.pop();
            res.push_back(data[curr].value());
            curr = 2*curr + 1;
        }
        return res;
    }

    vector<T> postOrderIterative(int idx){
        vector<T> res;
        stack<pair<T, int>> st;
        
        st.push({data[idx].value(), idx});

        while(!st.empty()){
            pair<T, int> item = st.top();
            st.pop();
            res.push_back(item.first);
            int left_c = 2 * item.second;

            if(left_c <= size and data[left_c].has_value()){
                st.push({data[left_c].value(), left_c});
            }
            if(left_c + 1 <= size and data[left_c+1].has_value()){
                st.push({data[left_c+1].value(), left_c+1});
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


template <typename T>
void printBinaryTree(BinaryTree<T> bt){
    printf("Size of Binary Tree: %d\n", bt.size);
    for(auto &i: bt.data){
        cout << (i.has_value() ? to_string(i.value()): "NIL") << " | ";
    }
    cout << endl;
}


template <typename T>
void printVector(vector<T> a, string s) {
    cout << "Printing " << s << " : " ;
    for(auto &i: a){
        cout << i << " | ";
    }
    cout << endl;
}


int main(){
    BinaryTree<int> bt(5);
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    printBinaryTree(bt);

    vector<int> preOrderRes, postOrderRes, inOrderRes;
    bt.preOrder(preOrderRes, 1);
    bt.inOrder(inOrderRes, 1);
    bt.postOrder(postOrderRes, 1);

    printVector(preOrderRes, "PreOrder Traversal");
    printVector(inOrderRes, "InOrder Traversal");
    printVector(postOrderRes, "PostOrder Traversal");

    cout << endl;

    vector<int> preOrderIterativeRes = bt.preOrderIterative(1);
    printVector(preOrderIterativeRes, "PreOrder Traversal"); 
    
    vector<int> inOrderIterativeRes = bt.inOrderIterative(1);
    printVector(inOrderIterativeRes, "InOrder Traversal"); 

    vector<int> postOrderIterativeRes = bt.postOrderIterative(1);
    printVector(postOrderIterativeRes, "PostOrder Traversal"); 
}


