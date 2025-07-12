#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> minusOfSortedArrays(vector<int> &n, vector<int> &m){
  int i = 0, j = 0, k = 0;
  vector<int> b;
  
  while( i<n.size() && j < m.size()){
    if (n[i] < m[j]){
      b.push_back(n[i]);
      k++;
      i++;
    }
    else if(n[i] > m[j]){
      j++;
    }
    else {
      i++;
      j++;
    }
  }

  if( j >= m.size() ){
    for(int l=i; l < n.size(); l++){
      b.push_back(n[l]);
      k++;
    }
  }

  return b;
}

void printVector(vector<int> &a){
  for(int i: a){
    cout << i << " ";
  }
  cout << endl;
}

int main(){
  vector<int> n {2,4,6,10,12,15};
  vector<int> m {3,5,6,9,10,12};
  vector<int> result = minusOfSortedArrays(n,m);
  printVector(result);
}
