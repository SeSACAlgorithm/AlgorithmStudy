#include <string>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

const int inf = 2e9;

int solution(vector<string> strs, string t)
{
    int answer = 0; 

    int n = t.size();
    
    vector<int> dp(n + 1, inf);
    
    unordered_set<int> sizes;
    
    for(const string& str : strs)
        sizes.insert(str.size());
    
    unordered_set<string> strSet(strs.begin(), strs.end());
    
    dp[0] = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        for(int size : sizes)
        {
            if(i >= size && strSet.count(t.substr(i - size, size)))
                dp[i] = min(dp[i], dp[i - size] + 1);
        }
    }
    

    return dp[n] != inf ? dp[n] : -1;
}
