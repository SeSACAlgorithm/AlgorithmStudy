#include <iostream>
#include <vector>

using namespace std;

void max_check(const vector<pair<int, int>>& eggs, int& max)
{
    int count = 0;
    for (const pair<int, int>& egg : eggs)
        if (egg.first <= 0)
            ++count;

    if (count > max)
        max = count;
}

void back_tracking(int N, int cur, vector<pair<int, int>>& eggs, int& max)
{
    if(cur >= N)
    {
        max_check(eggs, max);
        return;
    }

    if(eggs[cur].first <= 0)
    {
        back_tracking(N, cur + 1, eggs, max);
        return;
    }

    bool not_used = true;
    for(int i = 0; i < N; ++i)
    {
        if (i == cur) continue;

	    if(eggs[i].first > 0)
	    {
            not_used = false;
            // 계란 충돌
            eggs[cur].first -= eggs[i].second;
            eggs[i].first -= eggs[cur].second;

            int next = cur + 1;
            if (eggs[cur].first <= 0)
            {
                // 다음 달걀 선택하기
                for(; next < N; ++next)
                    if (eggs[next].first > 0)
                        break;
            }
            back_tracking(N, next, eggs, max);
            // 충돌 이전으로 복원
            eggs[cur].first += eggs[i].second;
            eggs[i].first += eggs[cur].second;
	    }
    }

    if(not_used)
        back_tracking(N, cur + 1, eggs, max);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> eggs(N);
    for(int i = 0; i < N; ++i)
        cin >> eggs[i].first >> eggs[i].second;

    int max = 0;
    back_tracking(N, 0, eggs, max);

    cout << max;
}