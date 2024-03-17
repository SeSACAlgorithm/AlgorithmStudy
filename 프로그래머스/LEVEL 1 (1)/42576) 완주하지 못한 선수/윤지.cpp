#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> map;
    
    for ( int i = 0; i < participant.size(); i ++)
    {
        if (map.find(participant[i]) == map.end())
        {
            map.insert(pair<string, int>(participant[i],1));
        }
        else
        {
            map[participant[i]] += 1;
        }
    }
    
    for(int i = 0; i < completion.size(); i ++)
    {
        map[completion[i]] -= 1;
    }
    
    for (auto iter = map.begin(); iter != map.end(); iter++)
    {
        if (iter->second == 1)
        {
            return iter->first;
        }
    }
    
    return answer;
}