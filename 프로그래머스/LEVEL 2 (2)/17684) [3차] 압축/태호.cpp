#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> M;
    int index = 26;

    for (int i = 0; i < index; ++i)
    {
        string str = ""; str += i + 'A';
        M.emplace(str, i + 1);
    }
    
    while (msg.size() > 1)
    {
        int cnt = 0;
        string str; str += msg[0];

        int k = -1;
        auto iter = M.find(str);
        while (iter != M.end())
        {
            if(msg.size() > cnt)
                str += msg[++cnt];
            else
                break;

            k = iter->second;
            iter = M.find(str);
        }

        if(k != - 1)
            answer.push_back(k);

        M.emplace(str, ++index);
        msg.erase(msg.begin(), msg.begin() + cnt);
    }

    if(!msg.empty())
        answer.push_back(M[msg]);


    return answer;
}
