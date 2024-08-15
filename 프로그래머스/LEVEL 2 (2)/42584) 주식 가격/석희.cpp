// 입력 - prices : 초 단위로 기록된 주식 가격
// 출력 - 가격이 떨어지지 않은 기간은 몇 초?

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer(prices.size());
    stack<int> s;

    for(int i = 0; i < prices.size(); i++)
    {
        // 하락했다면
        while(!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    
    // 하락을 겪지 않은 가격들
    while(!s.empty())
    {
        answer[s.top()] = prices.size() - s.top() - 1;
        s.pop();
    }
    
    return answer;
}