#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    auto target_it = find(words.begin(), words.end(), target);
    if(target_it == words.end())
        return 0;
    
    int target_idx = (target_it - words.begin());
    int len = begin.size();
    int answer = 0;
    vector<bool> check(words.size(), false);
    
    queue<pair<string, int>> que;
    que.push(pair<string, int>{begin, 0});
    string cur = "";
    int val = 0;
    while(false == que.empty())
    {
        pair<string, int> p = que.front();
        cur = p.first, val = p.second;
        if(cur == target) return val;
        que.pop();
        
        for(int i = 0 ; i < words.size(); ++i)
        {
            if(check[i]) continue;
            
            int count = 0;
            for(int j = 0; j < len; ++j)
                if(cur[j] != words[i][j]) ++count;
            
            if(count == 1)
            {
                check[i] = true;
                que.push(pair<string, int>{words[i], val + 1});
            }
        }
    }
    
    return answer;
}