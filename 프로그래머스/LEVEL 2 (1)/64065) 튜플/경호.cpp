#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    map<int, int> count;
    
    int len = 0, idx = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(isdigit(s[i]))
        {
            if(len == 0) idx = i;
            ++len;
        }
        else
        {
            if(len > 0)
            {
                ++count[stoi(s.substr(idx, len))];
                len = 0;
            }
        }
    }
    
    vector<pair<int, int>> sorted(count.begin(), count.end());
    sort(sorted.begin(), sorted.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second;});
    
    vector<int> answer(sorted.size());
    for(int i = 0; i < sorted.size(); ++i)
        answer[i] = sorted[i].first;
    return answer;
}