#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int ans = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i=0; i<A.size(); i++)
        ans += A[i] * B[i];

    return ans;
}
