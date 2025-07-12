
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> removeDuplicatesFromSortedArray(vector<int>& a){
  if(a.size() == 0)
    return {};

  int prev = a[0];
  vector<int> b{prev};

  for(int i=1; i < a.size(); i++) {
    if(a[i] == prev)
      continue;
    b.push_back(a[i]);
    prev = a[i];
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
  vector<int> arr {0,0,0,1,1,2,3,3,3,3,4,6,6};
  auto result = removeDuplicatesFromSortedArray(arr);
  printVector(result);
}
