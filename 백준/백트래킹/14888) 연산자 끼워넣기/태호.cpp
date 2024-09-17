#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, mn = 0x7f7f7f7f, mx = -0x7f7f7f7f;

int sign[4];

vector<int> numbers;

void Solve(int cur, int total)
{
    if (cur == n)
    {
        mn = min(total, mn);
        mx = max(total, mx);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (sign[i])
        {
            --sign[i];

            if(i == 0)
                Solve(cur + 1, total + numbers[cur]);

            else if (i == 1)
                Solve(cur + 1, total - numbers[cur]);

            else if (i == 2)
                Solve(cur + 1, total * numbers[cur]);

            else if (i == 3)
                Solve(cur + 1, total / numbers[cur]);

            ++sign[i];
        }
    }
        
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;


    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        numbers.push_back(x);
    }

    for(int i = 0; i < 4; ++i)
        cin >> sign[i];
       
    Solve(1, numbers[0]);

    cout << mx << '\n' << mn;
}
