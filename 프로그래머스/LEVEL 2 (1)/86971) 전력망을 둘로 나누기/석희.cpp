#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> road[101];

int bfs(int num1, int num2)
{
    int result = 1;
    bool check[101] = {
        false,
    };
    queue<int> q;

    q.push(num1);
    check[num1] = true;
    check[num2] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < road[x].size(); i++)
        {
            int y = road[x][i];

            if (false == check[y])
            {
                q.push(y);
                check[y] = true;
                result++;
            }
        }
    }

    return result;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 987654321;

    for (int i = 0; i < wires.size(); i++)
    {
        road[wires[i][0]].push_back(wires[i][1]);
        road[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];

        int result = bfs(x, y);
        answer = min(answer, abs(2 * result - n));
    }

    return answer;
}