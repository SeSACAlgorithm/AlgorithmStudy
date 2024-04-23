#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> stk;
    
    for(int i = 0; i < prices.size(); ++i)
    {
        while(false == stk.empty() && stk.top().first > prices[i])
        {
            answer[stk.top().second] = i - stk.top().second;
            stk.pop();
        }
        
        stk.push(pair<int, int>(prices[i], i));
    }
    
    while(false == stk.empty())
    {
        answer[stk.top().second] = prices.size() - stk.top().second - 1;
        stk.pop();
    }
    
    return answer;
}