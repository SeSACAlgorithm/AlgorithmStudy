#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int col, row;
    cin >> col >> row;

    vector<vector<int>> tomato(row, vector<int>(col, 0));
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int count = 0;
    vector<pair<int, int>> first_day;
    for (int y = 0; y < row; ++y)
    {
        for (int x = 0; x < col; ++x)
        {
            cin >> tomato[y][x];
            if (tomato[y][x] == 0) 
                ++count;
            else if (tomato[y][x] == 1)
            {
                first_day.emplace_back(y, x);
                visited[y][x] = true;
            }
        }
    }
    if(count == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> delta_y{ -1, 0, 1, 0 };
    vector<int> delta_x{ 0, 1, 0, -1 };

    int day = 0;
    queue<vector<pair<int, int>>> que;
    que.push(first_day);
    while(false == que.empty())
    {
        vector<pair<int, int>> today = que.front();
        vector<pair<int, int>> tomorrow;
        que.pop();

        for(const pair<int, int> point : today)
        {
            int y = point.first;
            int x = point.second;

	        for(int i = 0; i < 4; ++i)
	        {
                int next_y = y + delta_y[i];
                int next_x = x + delta_x[i];

                if (next_y < 0 || next_y >= row) continue;
                if (next_x < 0 || next_x >= col) continue;
                if (visited[next_y][next_x]) continue;

                if(tomato[next_y][next_x] == 0)
                {
                    tomato[next_y][next_x] = 1;
                    visited[next_y][next_x] = true;
                    --count;
                    tomorrow.emplace_back(next_y, next_x);
                }
	        }
        }
        ++day;

        if (false == tomorrow.empty())
            que.push(tomorrow);

        if (count == 0) break;
    }

    if (count > 0) cout << -1;
    else           cout << day;
}