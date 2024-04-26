#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    // step 1
    string sample = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string, int> dict;
    for(int i = 0; i < sample.size(); ++i)
        dict[sample.substr(i, 1)] = i + 1;
    int dict_idx = dict.size() + 1;
    
    string tmp = "";
    for(int idx = 0; idx < msg.size(); )
    {
        bool remain = true;
        // step 2
        for(int len = 1; idx + len <= msg.size(); ++len)
        {
            tmp = msg.substr(idx, len);
            if(dict[tmp] == 0)
            {
                dict[tmp] = dict_idx++;
                answer.emplace_back(dict[msg.substr(idx, len - 1)]);
                idx += len - 1;
                remain = false;
                break;
            }
        }
        if(remain)
        {
            answer.emplace_back(dict[msg.substr(idx, msg.size() - idx)]);
            break;
        }
    }
    
    return answer;
}