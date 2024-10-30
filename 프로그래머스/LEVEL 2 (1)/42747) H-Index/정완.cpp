#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int ans = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());   // vector 정렬

    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] >= i + 1)
            ans++;
    }
    
    return ans;
}
