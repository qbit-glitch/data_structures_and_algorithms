/**
 * Queue Implementation using Arrays
*/

#include <bits/stdc++.h>
using namespace std;

class QueueImpl{
    private:
    int start=-1, end=-1, s[10], curSize=0;

    public:
    void push(int x){
        if(curSize == (sizeof(s)/sizeof(int))){
            cout << "Queue is Full! Unable to push - " << x << endl;
            return;
        }
        if(start == -1 and end == -1){
            start = end = 0;
            s[end] = x;
        }
        else {
            end = ( end + 1 ) % (sizeof(s)/sizeof(int));
            s[end] = x;
        }
        curSize++;
    }

    void pop(){
        if(start==-1){
            cout << "Queue is Empty! Unable to pop()!" << endl;
            return;
        }
        if(start == end){
            start = end = -1;
            return;
        }
        start = (start + 1) % (sizeof(s)/sizeof(int));
        curSize--;
    }

    int top(){
        if(start == -1){
            cout << "Queue is Empty! Unable to refer to top()! | " << endl;
            return -1;    
        }
        return s[start];
    }

    int get_size(){
        return curSize;
    }
};

int main(){
    QueueImpl q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.top() << " " << q.get_size() << endl;
    q.pop();
    cout << q.top()<< " " << q.get_size() << endl;
    q.pop();
    q.pop();
    cout << q.top() << " " << q.get_size()<< endl;

    cout << q.get_size() << endl;
    
}