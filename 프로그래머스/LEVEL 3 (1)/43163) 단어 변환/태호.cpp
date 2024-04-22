#include <string>
#include <vector>
#include <queue>

using namespace std;

int vis[52];

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    pair<string, int> str;

    queue<pair<string, int>> Q;
    Q.push({begin, 0});

    while (str.first != target)
    {
        str = Q.front(); Q.pop();

        for (int i = 0; i < words.size(); ++i)
        {
            int k = 0;

            if(vis[i])
                continue;

            for (int j = 0; j < words[i].size(); ++j)
            {
                if (str.first[j] == words[i][j])
                    ++k;
            }

           
            if (k == str.first.size() - 1)
            {
                if(target == words[i])
                    return str.second + 1;

                vis[i] = str.second + 1;
                Q.push({words[i], vis[i]});
            }

        }

        if(Q.size() == 0)
            break;
    }

    
    return answer;
}
