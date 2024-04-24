#include <string>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> Q;
    list<int> List;

    for (int i = 0; i < priorities.size(); ++i)
    {
        Q.push({ i, priorities[i] });
        List.push_back(priorities[i]);
    }

    List.sort();

    vector<int> vis(Q.size());

    while (!vis[location])
    {
        auto cur = Q.front(); Q.pop();

        if (*--List.end() == cur.second)
        {
            List.pop_back();
            vis[cur.first] = ++answer;
        }
        else
            Q.push(cur);
    }


    return vis[location];
}
