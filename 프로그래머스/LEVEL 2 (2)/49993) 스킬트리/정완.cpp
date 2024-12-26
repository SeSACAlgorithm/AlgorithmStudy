#include <string>
#include <vector>

using namespace std;

bool chk_skill_tree(string skill, string skill_tree)
{
    int index = 0;
    
    for(auto s_t : skill_tree)
    {
        if(skill.find(s_t) == string::npos)
            continue;
        
        if(index < skill.size() && skill[index] == s_t)
            index++;
        
        else
            return false;
    }
    
    return true;
}
int solution(string skill, vector<string> skill_trees) {
    int ans = 0;
    
    for(int i=0; i<skill_trees.size(); i++)
        if(chk_skill_tree(skill, skill_trees[i]))
           ans++;
   
    return ans;
}
