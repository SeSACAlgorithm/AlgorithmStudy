#include <stack>

using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> stk;
    while(n > 2)
    {
        stk.push(n % 3);
        n /= 3;
    }
    stk.push(n);
    
    int multiplier = 1;
    while(stk.size() > 0)
    {
        answer += stk.top() * multiplier;
        stk.pop();
        multiplier *= 3;
    }
    return answer;
}