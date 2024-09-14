#include <iostream>

using namespace std;

int n;
pair<int, int> board[10];

int result = 0;

void Answer()
{
    int k = 0;

    for (int i = 0; i < n; ++i)
    {
        if (board[i].first <= 0)
            ++k;
    }

    result = max(result, k);
}

void Solve(int cur, int index)
{
    if (cur == n)
    {
        Answer();
        return;
    }

    if (board[cur].first <= 0)
    {
        Solve(cur + 1, index);
        return;
    }


    bool cond = false;

    for (int i = 0; i < n; ++i)
    {
        if(board[i].first <= 0 || i == cur) continue;

        cond = true;
        board[i].first -= board[cur].second;
        board[cur].first -= board[i].second;
        
        Solve(cur + 1, i);

        board[i].first += board[cur].second;
        board[cur].first += board[i].second;
    }

    if(!cond)
        Answer();
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> board[i].first;
        cin >> board[i].second;
    }

    Solve(0, 0);

    cout << result;

    return 0;
}
