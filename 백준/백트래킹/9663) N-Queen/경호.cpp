#include <iostream>
#include <vector>

using namespace std;

void back_tracking(int N, int count, vector<int>& queen, int& ans)
{
    if(count == N)
    {
        ++ans;
        return;
    }

    for(int i = 0; i < N; ++i)
    {
        bool able = true;
        // 놓을 수 있는 위치인지 검사
        for (int j = 0; j < count; ++j)
        {
            if (queen[j] == i || count - j == abs(queen[j] - i))
            {
                able = false;
                break;
            }
        }
        if (false == able) continue;

        queen[count] = i;
        back_tracking(N, count + 1, queen, ans);
        queen[count] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int answer = 0;
    vector<int> queen(N, 0);
    back_tracking(N, 0, queen, answer);

    cout << answer;
}