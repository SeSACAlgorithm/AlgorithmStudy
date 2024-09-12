#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
bool visit[22];
int values[22];
int track[22];
int x = 0;
int reuslt = 0;

void Solve(int k)
{
    if (m == x)
    {
        ++reuslt;
    }

    for (int i = 1; i <= n; ++i)
    {
        if(visit[i]) continue;

        if (k != 0)
        {
            if (track[k - 1] > i)
                continue;
        }

        x += values[i];
        track[k] = i;
        visit[i] = true;
        Solve(k + 1);
        x -= values[i];
        visit[i] = false;

    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        cin >> values[i];

    Solve(0);

    if(m == 0)
        --reuslt;

    cout << reuslt;
}
