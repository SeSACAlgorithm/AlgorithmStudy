#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string ans = "";
    stack<char> s;
    
    for(char num : number)
    {
        while(!s.empty() && s.top()<num && k>0)
        {
            s.pop();
            k--;
        }
        s.push(num);
    }
    
    while(k>0)
    {
        s.pop();
        k--;
    }
    
    while(!s.empty())
    {
        ans = s.top() + ans;
        s.pop();
    }
    
    return ans;
}
