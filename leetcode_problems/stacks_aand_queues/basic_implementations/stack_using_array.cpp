/**
 * Implement Stack using Array
*/

#include <bits/stdc++.h>
using namespace std;

class stackImpl{
    private:
    int a[10];
    int t = -1;

    public:
    void push(int x){
        t += 1;
        a[t] = x;
    }

    void pop(){
        if(t==0)
            t = -1;
        t--;
    }

    int top(){
        return a[t];
    }

    int size(){
        return sizeof(a)/sizeof(int);
    }
};

int main(){
    stackImpl st;
    st.push(12);
    st.push(13);
    st.push(14);
    cout << st.top() << endl;
    st.pop();
    // cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
}