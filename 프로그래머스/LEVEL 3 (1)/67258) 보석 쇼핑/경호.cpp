#include <string>
#include <vector>
#include <map>

using namespace std;

int get_min_idx(const map<string, int>& idxes)
{
    int min = 100000;
    
    for(auto it = idxes.begin(); it != idxes.end(); ++it)
        if(it->second < min)
            min = it->second;
    
    return min;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    
    int start = 0, end = 0;
    map<string, int> idxes;
    bool new_jewel = false;
    
    for(int i = 0; i < gems.size(); ++i, ++end)
    {
        new_jewel = (idxes.find(gems[i]) == idxes.end());
        idxes[gems[i]] = i;
        end = i;
        // 새로운 보석이 들어온 경우 무조건 갱신
        if(new_jewel)
        {
            answer[0] = start + 1;
            answer[1] = end + 1;
            continue;
        }
        // 이미 있는 보석인 경우 동일한 보석을 만날 때 갱신
        if(gems[end] == gems[start])
        {
            start = get_min_idx(idxes);
            if(end - start < answer[1] - answer[0])
            {
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
        }
    }
    
    return answer;
}