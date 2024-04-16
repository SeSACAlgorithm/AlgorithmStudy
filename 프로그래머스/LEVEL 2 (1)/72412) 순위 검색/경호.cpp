#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size());
    map<string, vector<int>> m;
    
    string lang = "", job = "", year = "", food = "", score = "";
    const string ANY = "-";
    int score_num = 0;
    for(const string& str : info)
    {
        istringstream ss(str);
        ss >> lang >> job >> year >> food >> score;
        score_num = stoi(score);
        m[lang + job + year + food].push_back(score_num);
        
        m[ANY + job + year + food].push_back(score_num);
        m[lang + ANY + year + food].push_back(score_num);
        m[lang + job + ANY + food].push_back(score_num);
        m[lang + job + year + ANY].push_back(score_num);
        
        m[ANY + ANY + year + food].push_back(score_num);
        m[ANY + job + ANY + food].push_back(score_num);
        m[ANY + job + year + ANY].push_back(score_num);
        m[lang + ANY + ANY + food].push_back(score_num);
        m[lang + ANY + year + ANY].push_back(score_num);
        m[lang + job + ANY + ANY].push_back(score_num);
        
        m[ANY + ANY + ANY + food].push_back(score_num);
        m[ANY + ANY + year + ANY].push_back(score_num);
        m[ANY + job + ANY + ANY].push_back(score_num);
        m[lang + ANY + ANY + ANY].push_back(score_num);
        
        m["----"].push_back(score_num);
    }
    
    string tmp = "";
    int target_score = 0;
    for(int i = 0; i < query.size(); i++)
    {
        stringstream ss(query[i]);
        ss >> lang >> tmp >> job >> tmp >> year >> tmp >> food >> score;
        target_score = stoi(score);
        
        vector<int>& target = m[lang + job + year + food];
        answer[i] = count_if(target.begin(), target.end(), [&](int num) {return num >= target_score;});
    }
    
    return answer;
}