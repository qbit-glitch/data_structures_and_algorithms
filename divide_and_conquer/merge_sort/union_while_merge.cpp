#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// Union of 2 sorted arrays n,m
vector<int> unionOfSortedArrays(vector<int>& n, vector<int>& m){
  int i = 0, j = 0, k = 0;
  vector<int> b {};
  while(i < n.size() && j < m.size()){
    if (n[i] < m[j]) {
      b.push_back(n[i]);
      i++;
    }
    else if (n[i] > m[j]){
      b.push_back(m[j]);
      j++;
    }
    else {
      b.push_back(n[i]);
      i++;
      j++;
    }
    k++;
  }

  if (i >= n.size()){
    for(int l=j; l<m.size(); l++){
      b.push_back(m[l]);
      k++;
    }
  }
  if (j >= m.size()){
    for(int l=i; l<n.size(); l++){
      b.push_back(n[l]);
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
  vector<int> result = unionOfSortedArrays(n,m);
  cout << "Union of n,m sorted arrays:";
  printVector(result);
}
