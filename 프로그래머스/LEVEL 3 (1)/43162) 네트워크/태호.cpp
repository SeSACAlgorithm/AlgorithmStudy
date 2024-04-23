#include <string>
#include <vector>

using namespace std;

int vis[202];

vector<vector<int>> computer;

void dfs(int cur, const vector<int>& computers, int idx)
{
    if (idx != 0)
        vis[cur] = idx;

    for (int i = 0; i < computers.size(); ++i)
    {
        if (vis[i] || !computers[i]) continue;
        dfs(i, computer[i], idx + 1);
    }

}


int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    computer = computers;

    for (int i = 0; i < n; ++i)
        dfs(i, computers[i], 0);

    for(int i = 0; i < n; ++i)
        if(vis[i] == 1)
            ++answer;

    return answer;
}
