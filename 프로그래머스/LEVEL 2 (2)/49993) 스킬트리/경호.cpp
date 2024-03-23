#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> sMap;
    for(int i = 0; i < skill.size(); i++)
        sMap[skill[i]] = i + 1;
    
    for(string s : skill_trees)
    {
        int idx = 1;
        bool canLearn = true;
        for(int i = 0; i < s.size(); i++)
        {
            if(sMap[s[i]] > idx)
            {
                canLearn = false;
                break;
            }
            
            if(sMap[s[i]] == 0) continue;
            
            idx++;
        }
        if(canLearn)
            answer++;
    }
    
    return answer;
}