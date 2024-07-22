#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

bool id_check(const string& id, const string& ban)
{
    if(id.size() != ban.size()) 
        return false;
    
    bool is_banned = true;
    for(int i = 0; i < ban.size(); ++i)
    {
        if(ban[i] == '*') continue;
        
        if(id[i] != ban[i])
        {
            is_banned = false;
            break;
        }
    }
    return is_banned;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    set<vector<int>> unique_case;
    
    stack<pair<vector<bool>, vector<int>>> ban_case;
    ban_case.push(pair<vector<bool>, vector<int>>(vector<bool>(user_id.size(), false),vector<int>(0)));
    
    int last = banned_id.size() - 1;
    while (false == ban_case.empty())
    {
        vector<bool> used = ban_case.top().first;
        vector<int> ban_idxes = ban_case.top().second;
        int idx = ban_idxes.size();
        ban_case.pop();

        for (int i = 0; i < user_id.size(); ++i)
        {
            if(used[i]) 
                continue;
            if (false == id_check(user_id[i], banned_id[idx]))
                continue;

            vector<bool> copy_used(used.begin(), used.end());
            copy_used[i] = true;
            vector<int> copy_idxes(ban_idxes.begin(), ban_idxes.end());
            copy_idxes.emplace_back(i);
            if (idx == last)
            {
                sort(copy_idxes.begin(), copy_idxes.end());
                unique_case.insert(copy_idxes);
            }
            else
                ban_case.push(pair<vector<bool>, vector<int>>(copy_used, copy_idxes));
        }
    }
    
    return unique_case.size();
}