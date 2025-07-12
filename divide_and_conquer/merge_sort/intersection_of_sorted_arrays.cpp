#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> intersectionOfSortedArrays(vector<int> &n, vector<int> &m){
  int i=0, j=0, k=0;
  vector<int> b;

  while(i<n.size() && j < m.size() ){
    if(n[i] < m[j])
      i++;
    else if(m[j] < n[i] )
      j++;

    else{
      b.push_back(n[i]);
      i++;
      j++;
      k++;
    }
  }
  return b;
}

void printVector(vector<int>& a){
  for(int i: a){
    cout << i << " ";
  }
  cout << endl;
}

int main(){
  vector<int> n {2,4,6,10,12,15};
  vector<int> m {3,5,6,9,10,12};
  vector<int> result = intersectionOfSortedArrays(n,m);
  printVector(result);
}

