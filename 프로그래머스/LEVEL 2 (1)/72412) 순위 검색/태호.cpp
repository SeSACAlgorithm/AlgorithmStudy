#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<int>> freq;

vector<int> solution(vector<string> info, vector<string> query) 
{
    vector<int> answer;


    for (int i = 0; i < info.size(); ++i)
    {
        stringstream ss;
        ss.str(info[i]);

        string str = "";

        vector<string> v;

        while (!ss.eof())
        {
            ss >> str;
            v.push_back(str);
        }

        // - (0개)        
        freq[v[0] + v[1] + v[2] + v[3]].push_back(stoi(v[4]));

        // - (1개)
        freq["-" + v[1] + v[2] + v[3]].push_back(stoi(v[4]));
        freq[v[0] + "-" + v[2] + v[3]].push_back(stoi(v[4]));
        freq[v[0] + v[1] + "-" + v[3]].push_back(stoi(v[4]));
        freq[v[0] + v[1] + v[2] + "-"].push_back(stoi(v[4]));

        // - (2개)
        // 12, 13, 14, 23, 24, 34

        freq["--" + v[2] + v[3]].push_back(stoi(v[4]));;
        freq["-" + v[1] + "-" + v[3]].push_back(stoi(v[4]));;
        freq["-" + v[1] + v[2] + "-"].push_back(stoi(v[4]));;
        freq[v[0] + "--" + v[3]].push_back(stoi(v[4]));;
        freq[v[0] + "-" + v[2] + "-"].push_back(stoi(v[4]));;
        freq[v[0] + v[1] + "--"].push_back(stoi(v[4]));;

        // -(3개)
        // 123, 124, 134, 234 
        freq[v[0] + "---"].push_back(stoi(v[4]));;
        freq["-" + v[1] + "--"].push_back(stoi(v[4]));;
        freq["--" + v[2] + "-"].push_back(stoi(v[4]));;
        freq["---" + v[3]].push_back(stoi(v[4]));;

        // -(4개)
        freq["----"].push_back(stoi(v[4]));

    }

    for (int i = 0; i < query.size(); ++i)
    {
        stringstream ss;
        ss.str(query[i]);

        string str = "";
        string result = "";

        vector<string> v;

        while (!ss.eof())
        {
            ss >> str;

            if(str == "and")
                continue;

            v.push_back(str);
        }

        result += v[0] + v[1] + v[2] + v[3];

        int correctScore = stoi(v[4]);

        int cnt = 0;

        for (int score : freq[result])
        {
            if(correctScore <= score)
                ++cnt;
        }

        answer.push_back(cnt);
    }

    return answer;
}
