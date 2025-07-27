#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> sliceMatrix(vector<vector<int>> a, int r_s, int r_e, int c_s, int c_e){
    vector<vector<int>> result(r_e - r_s + 1, vector<int>(c_e - c_s + 1));
    int k = 0;
    for(int i=r_s; i <= r_e; i++){
        for(int j = c_s; j <= c_e; j++){
            result[k].push_back(a[i][j]);
        }
        k++;
    }
    return result;
}

vector<vector<int>> matMul(vector<vector<int>>&a , vector<vector<int>>& b){
    if(a[0].size() != b.size()){
        cout << "error during matrix multplication: size not compatible" << endl;
        return vector<vector<int>> {{-1}};
    }
    vector<vector<int>> result(a.size(), vector<int>(b.size(),0));
    for(int i=0; i < a.size(); i++){
        for(int j = 0; j<a[0].size(); j++){
            for(int k = 0; k < b.size(); k++){
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}



vector<vector<int>> dAndCMM(vector<vector<int>>& a, vector<vector<int>>& b){
    
    // a,b two matrices of order nxn
    if(a.size() <= 2 && b.size() <= 2)
        return matMul(a,b);
    
    auto subMatricesOfA = divideMatrices(a);
    auto subMatricesOfB = divideMatrices(b);

    auto A11 = subMatricesOfA[0];
    auto A12 = subMatricesOfA[1];
    auto A21 = subMatricesOfA[2];
    auto A22 = subMatricesOfA[3];

    auto B11 = subMatricesOfB[0];
    auto B12 = subMatricesOfB[1];
    auto B21 = subMatricesOfB[2];
    auto B22 = subMatricesOfB[3];

    auto p = dAndCMM(A11, B11);
    auto q = dAndCMM(A11, B12);
    auto r = dAndCMM(A12, B21);
    auto s = dAndCMM(A12, B22);
    auto t = dAndCMM(A21, B21);
    auto t = dAndCMM(A21, B22);
    auto v = dAndCMM(A22, B21);
    auto w = dAndCMM(A22, B22);
    
    
    
    
    return vector<vector<int>> {{1,2}};
}


void printVector(vector<vector<int>> c){
    for(auto &i: c){
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
}

auto divideMatrices(vector<vector<int>> &a){
    int r = a.size();
    int c = a[0].size();

    int m_r = a.size()/2;
    int m_c = a[0].size()/2;

    vector<vector<int>> A11 = sliceMatrix(a, 0, m_r, 0, m_c);
    vector<vector<int>> A12 = sliceMatrix(a, 0, m_r, m_c+1, c-1);
    vector<vector<int>> A21 = sliceMatrix(a, m_r+1, r-1, 0, m_c );
    vector<vector<int>> A22 = sliceMatrix(a, m_r+1, r-1, m_c+1, c-1);

    return vector<vector<vector<int>>> {A11, A12, A21, A22};
}



int main(){
    vector<vector<int>> a {{1,2,3}, {4,5,6}};
    vector<vector<int>> b {{1,2}, {3,4}, {5,6}}; 
    
    printVector(sliceMatrix(b, 0,1,0,1));
}