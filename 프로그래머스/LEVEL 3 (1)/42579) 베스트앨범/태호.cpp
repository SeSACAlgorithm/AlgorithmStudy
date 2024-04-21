#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> M;

    for (int i = 0; i < genres.size(); ++i)
    {
        M[genres[i]].push_back({ plays[i], i });
    }
       
    vector<vector<tuple<int, int, string>>> Mode;

    for (auto& iter : M)
    {
        int mx = 0;
        vector<tuple<int, int, string>> vec;

        for (int i = 0; i < iter.second.size(); ++i)
            vec.push_back({ iter.second[i].first, iter.second[i].second, iter.first });

        sort(vec.begin(), vec.end(), [](tuple<int, int, string> &v1, tuple<int, int, string>& v2)
        {       
            int x1, y1; string k1;
            tie(x1, y1, k1) = v1;

            int x2, y2; string k2;
            tie(x2, y2, k2) = v2;

            if (x1 == x2)
                return y1 < y2;

            return x1 > x2;
            
        });
        Mode.push_back(vec);

        int a = 0;
    }

    sort(Mode.begin(), Mode.end(), [](vector<tuple<int, int, string>>& v1, vector<tuple<int, int, string>>& v2)
    {
            int a = 0;

            int x, y; string k;


            for (int i = 0; i < v1.size(); ++i)
            {
                tie(x, y, k) = v1[i];
                a += x;
            }
               

            int b = 0;

            for (int i = 0; i < v2.size(); ++i)
            {
                tie(x, y, k) = v2[i];
                b += x;
            }

            return a > b;
    });

    for(int i = 0; i < Mode.size(); ++i)
    {


        int x, idx = 0; string dump;

        if (Mode[i].size() == 1)
        {
            tie(x, idx, dump) = Mode[i][0];
            answer.push_back(idx);
        }
        else
        {
            tie(x, idx, dump) = Mode[i][0];
            answer.push_back(idx);

            tie(x, idx, dump) = Mode[i][1];
            answer.push_back(idx);
        }
    }


    return answer;
}
