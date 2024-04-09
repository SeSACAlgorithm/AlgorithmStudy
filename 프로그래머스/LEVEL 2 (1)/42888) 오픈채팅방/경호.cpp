#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, vector<int>> past;
    map<string, string> final_name;
    map<string, int> code{{"Enter", 0}, {"Leave", 1}, {"Change", 2}};
    
    string enter = "님이 들어왔습니다.";
    string exit = "님이 나갔습니다.";
    
    string action = "", id = "", name = "";
    int idx = 0;
    for(string s : record)
    {
        stringstream ss(s);
        ss >> action >> id >> name;
        idx = code[action];
        
        switch(idx)
        {
        case 0: // Enter
            answer.push_back(name + enter);
            final_name[id] = name;
                
            if(past.find(id) != past.end()) // 기존 접속 기록이 있는 경우
                past[id].push_back(answer.size() - 1);
            else
                past[id] = vector<int>(1, answer.size() - 1);
            break;
        case 1: // Leave
            answer.push_back(final_name[id] + exit);
            past[id].push_back(answer.size() - 1);
            break;
        case 2: // Change
            final_name[id] = name;
            break;
        }
    }
    
    // 닉네임 변경
    for(auto it = final_name.begin(); it != final_name.end(); it++)
    {
        id = it->first;
        name = it->second;
        
        vector<int> list = past[id];
        for(int i = 0; i < list.size(); i++)
        {
            string target = answer[list[i]];
            for(int j = 0; j < target.size(); j++)
            {
                if(isalpha(target[j]) || isdigit(target[j])) continue;

                target = name + target.substr(j, target.size() - j);
                answer[list[i]] = target;
                break;
            }
        }
    }
    
    
    
    return answer;
}