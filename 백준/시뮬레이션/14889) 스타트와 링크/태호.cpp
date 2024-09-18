#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, half, result = 0x7f7f7f7f;

int board[21][21];
bool visited[21];

int TeamAbs()
{
    int start = 0, link = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(i == j) continue;

            if (visited[i] && visited[j])
                start += board[i][j];

            else if(!visited[i] && !visited[j])
                link += board[i][j];
        }   
    }

    return abs(start - link);
}

void Solve(int cur, int index)
{
    if (cur == half)
    {
        result = min(result, TeamAbs());
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && index < i)
        {
            visited[i] = true;
            Solve(cur + 1, i);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    half = n / 2;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    Solve(0, 0);

    cout << result;
}
