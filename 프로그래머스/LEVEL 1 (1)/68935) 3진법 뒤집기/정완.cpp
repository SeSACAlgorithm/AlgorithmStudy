#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n) {
    int ans = 0;
    stack<int> stk;
    
    while( n > 2 )
    {
        stk.push(n%3);
        n /= 3;
    }
    
    stk.push(n);
    
    int a = 1;
    
    while(stk.size() > 0)
    {
        ans += stk.top() * a;
        stk.pop();
        a *= 3;
    }
    
    return ans;
}
