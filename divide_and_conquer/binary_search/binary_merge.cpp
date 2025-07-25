#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Function declarations
vector<int> merge(const vector<int>& a, int l1, int h1, const vector<int>& b, int l2, int h2);
int medianUsingBinaryMerge(const vector<int>& a, int l1, int h1, const vector<int>& b, int l2, int h2);
void printVector(const vector<int>& a);


int medianUsingBinaryMerge(const vector<int>& a, int l1, int h1, const vector<int>& b, int l2, int h2){
    while(h1-l1 > 1 and h2-l2 > 1){
        int m1 = (l1+h1)/2;
        int m2 = (l2+h2)/2;
        if(a[m1] < b[m2]){
            l1 = m1;
            h2 = m2;
        }
        else if(a[m1] > b[m2]){
            h1 = m1;
            l2 = m2;
        }
        else {
            return a[m1];
        }
    }
    vector<int> newArr = merge(a,l1,h1,b,l2,h2);
    return newArr[newArr.size()/2];
}



vector<int> merge(const vector<int>& a, int l1, int h1, const vector<int>& b, int l2, int h2){
    vector<int> result;
    int i=l1, j=l2;
    while(i <= h1 and j <= h2){
        if(a[i] <= b[j]){
            result.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j]){
            result.push_back(b[j]);
            j++;
        }
    }
    if (i > h1){
        for(int k = j; k <= h2; k++)
            result.push_back(a[k]);
    }

    else if (j > h2){
        for(int k = i; k <= h1; k++)
            result.push_back(a[k]);
    }
    printVector(result);
    return result;
}

void printVector(const vector<int>& a){
    for(auto i: a){
        cout << i << " ";
    }
    cout << endl;
}


int main(){
    vector<int> a {2,4,5,6,7,8,10,80,90,92,94,98};
    vector<int> b {50,51,52,53,54,56,60,61,62,63,64,65};
    cout << medianUsingBinaryMerge(a,0,a.size()-1, b,0,b.size()-1) << endl;
}

