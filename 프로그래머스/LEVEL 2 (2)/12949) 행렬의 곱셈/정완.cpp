/*
A와 B의 곱 C가 정의되려면
행(가로) 열(새로)

1. 행렬 A의 열의 개수 = 행렬 B의 행의 개수
2. C의 크기 = A의 행 개수 × B의 열 개수
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> ans;    // 행렬 C 저장할 2차원 벡터                   
    
    // 행렬 A의 각 행 반복
    for(int i=0; i<arr1.size(); i++)
    {
        vector<int> v;  // 행렬 C의 한 행을 저장할 벡터
        
        for(int j=0; j<arr2[0].size(); j++) // 행렬 B의 각 열 반복
        {
            int sum = 0;
            
            for(int k=0; k<arr1[0].size(); k++) // A의 i행 * B의 j열 각 요소 곱하고 더함
                sum += arr1[i][k] * arr2[k][j];
            
            v.push_back(sum);
        }
        
        ans.push_back(v);
    }
    
    return ans;
}
