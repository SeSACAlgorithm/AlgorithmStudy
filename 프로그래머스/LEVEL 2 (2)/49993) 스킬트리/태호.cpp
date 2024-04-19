#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); ++i)
    {

        queue<char> S;
        string temp = skill;
        bool b = false;

     for(int j = 0; j < skill_trees[i].size(); ++j)
         S.push(skill_trees[i][j]);

     for (int j = 0; j < skill_trees[i].size(); ++j)
     {
         char c = S.front(); S.pop();
         auto iter = find(temp.begin(), temp.end(), c);
         
         if (iter != temp.end())
         {
             if (temp[0] == c)
                 temp.erase(temp.begin());
             else
             {
                 b = true;
                 break;
             }
         }
     }

     if(!b) 
         ++answer;
    }

    return answer;
}
