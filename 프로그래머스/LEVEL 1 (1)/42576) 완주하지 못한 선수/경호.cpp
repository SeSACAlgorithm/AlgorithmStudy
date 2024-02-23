#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for(int i = 0; i < participant.size(); i++)
        m[participant[i]]++;
    
    for(int i = 0; i < completion.size(); i++)
        m[completion[i]]--;
                  
    string answer = "";
    for(int i = 0; i < participant.size(); i++)
    {
        if(m[participant[i]] > 0)
        {
            answer = participant[i];
            break;
        }
    }   
    return answer;
}