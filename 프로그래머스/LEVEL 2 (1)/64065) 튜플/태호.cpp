#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    bool in;
    string k = "";

    vector<vector<int>> vec;
    vector<int> temp;

    for(int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == '{')
        {
            in = true;
        }
        else  if (s[i] == '}')
        {
            if (k != "")
            {
                temp.push_back(stoi(k));
                k = "";
            }

            vec.push_back(temp);
            temp.clear();
            in = false;
        }
        else if (in && s[i] == ',')
        {
            temp.push_back(stoi(k));
            k = "";
        }
        else if (in)
        {
            k += s[i];
        }
    }

    sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a.size() < b.size();
    });


    for (int i = 0;  i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[i].size(); ++j)
        {
            auto iter = find(answer.begin(), answer.end(), vec[i][j]);
            

            if(iter == answer.end())
                answer.push_back(vec[i][j]);
        }
        
    }

    return answer;
}
