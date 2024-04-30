#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    int sumA = 0;
    int sumB = 0;
    
    for(int i = 0 ; i < A.size(); i++){
        sumA += A[i];
    } 
    for(int i = 0 ; i < B.size(); i++){
        sumB += B[i];
    } 
    
    if(sumA <= sumB){
        sort(A.begin(), A.end(), greater<>());
        sort(B.begin(), B.end());
    } else {
        sort(B.begin(), B.end(), greater<>());
        sort(A.begin(), A.end());
    }
    
    int totSum = 0;
    
    for(int j = 0 ; j < A.size(); j++){
        totSum += A[j]*B[j];
    }
    
    
    answer = totSum;
    
    return answer;
}
