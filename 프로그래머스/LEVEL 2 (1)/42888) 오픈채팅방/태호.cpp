#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> M;
    vector<pair<string, string>> vec;

    for (int i = 0; i < record.size(); ++i)
    {
        stringstream ss;
        ss.str(record[i]);
        
        while (!ss.eof())
        {
            string str;
            string id;
            
            ss >> str;

            if ("Enter" == str)
            {
                ss >> id; ss >> str;

                auto iter = M.find(id);

                if(iter != M.end())
                    M[id] = str;
                else
                    M.emplace(id, str);
                
                vec.push_back({id, "Enter"});
            }
            else if ("Leave" == str)
            {
                ss >> id;
                vec.push_back({ id, "Leave" });
            }
            else if ("Change" == str)
            {
                string Changename;
                ss >> id; ss >> Changename;
                M[id] = Changename;
            }

        }
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        string str = "님이 ";

        if ("Enter" == vec[i].second)
        {
            str += "들어왔습니다.";
        }
        else
        {
            str += "나갔습니다.";
        }

        answer.push_back(M[vec[i].first] + str);
    }

    return answer;
}
