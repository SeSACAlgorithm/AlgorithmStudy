#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

bool visit[9];
int arr[9];

vector<int> nums;

void solve(int index, int now)
{
    // 출력하고자 하는 길이에 도달하면 출력
    if (index == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int last = 0;
    for (int i = now; i < N; i++)
    {
        if (visit[i] || last == nums[i]) continue;

        visit[i] = true;
        arr[index] = nums[i];
        last = arr[index];

        solve(index + 1, i);

        visit[i] = false;
    }
}

int main(void)
{
    int num;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    solve(0, 0);
}