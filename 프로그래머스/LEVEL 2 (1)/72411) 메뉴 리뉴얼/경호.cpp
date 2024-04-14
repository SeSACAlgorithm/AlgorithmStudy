#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void dfs(string target, string cur, int targetLen, int lastIdx, vector<bool>& used, vector<string>& result)
{
    if (cur.size() == targetLen)
    {
        result.push_back(cur);
        return;
    }

    for (int i = lastIdx; i < target.size(); i++)
    {
        if (used[i]) continue;

        used[i] = true;
        dfs(target, cur + target[i], targetLen, i, used, result);
        used[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string& s : orders)
        sort(s.begin(), s.end());
    
    for(int idx = 0; idx < course.size(); idx++)
    {
        int max = 0;
        map<string, int> count_map;
        
        vector<string> result;
        for(string& s : orders)
        {
            if(course[idx] > s.size()) continue;
            
            vector<bool> used(s.size(), false);
            dfs(s, "", course[idx], 0, used, result);
            for(string& res : result)
            {
                count_map[res]++;
                if(count_map[res] > max)
                    max = count_map[res];
            }
            result.clear();
        }
        
        if(max < 2) continue;
        
        for(auto it = count_map.begin(); it != count_map.end(); it++)
            if(it->second == max)
                answer.push_back(it->first);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}