#include <iostream>
#include <vector>

using namespace std;

int N;
bool visit[9];
vector<int> v;

void solve(int index)
{
    if (index == N)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }

        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (visit[i]) continue;

        visit[i] = true;
        v.push_back(i);

        solve(index + 1);

        visit[i] = false;
        v.pop_back();
    }
}

int main(void)
{
    cin >> N;

    solve(0);
}