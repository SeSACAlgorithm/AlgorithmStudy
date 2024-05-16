#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct State
{
    vector<string> route;
    vector<bool> passed;
    
    State() {}
    State(vector<string> r, vector<bool> p) : route(r), passed(p) {}
};

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end(), [](vector<string>& a, vector<string>& b) {
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });
    
    queue<State> que;
    que.push(State(vector<string>{"ICN"}, vector<bool>(tickets.size())));
    
    State cur;
    while(false == que.empty())
    {   
        cur = que.front();
        que.pop();
        if(cur.route.size() == tickets.size() + 1)
            return cur.route;
        
        for(int i = 0; i < tickets.size(); ++i)
        {
            if(tickets[i][0] != cur.route.back()) continue;
            if(cur.passed[i]) continue;
            
            vector<string> r(cur.route.begin(), cur.route.end());
            vector<bool> p(cur.passed.begin(), cur.passed.end());
            r.emplace_back(tickets[i][1]);
            p[i] = true;
            que.push(State(r, p));
        }
    }
    
    return answer;
}