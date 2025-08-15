/**
 * Leetcode-75: Sort Colors
*/

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a){
    for(auto &i: a)
        cout << i << " ";
    cout << endl;
}

void sortColorsBrute(vector<int> &a){
    vector<int> b (a.size());
    int k = 0; 

    for(int i=0; i<=2; i++){
        for(int j=0; j < a.size(); j++){
            if (a[j] == i){
                b[k] = i;
                k++;
            }
        }
    }

    for(int i=0; i<a.size(); i++)
        a[i] = b[i];
}

void sortColorsBetter(vector<int> &a){
    vector<int> b(3,0);
    for(int i=0; i< a.size(); i++){
        b[a[i]]++;
    }
    int k = 0;
    for(int i=0; i<b.size(); i++){
        while(b[i] != 0){
            a[k] = i;
            k++;
            b[i]--;
        }
    }
}

void sortColorOptimal(vector<int> &a){
    int low=0, mid=0, high = a.size() - 1;
    while(mid <= high){
        if(a[mid] == 0){
            swap(a[low], a[mid]);
            low++; mid++;
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid], a[high]);
            high--;
        }
    }
}




int main(){
    vector<int> a{2,0,2,1,1,0};
    sortColorOptimal(a);
    printArray(a);
}