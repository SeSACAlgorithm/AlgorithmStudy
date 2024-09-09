#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;
map<int, int> check;

vector<int> answer;

void solve(int index)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 같은 숫자 여러번 사용 가능 (i를 0부터 시작)
    for (int i = 0; i < nums.size(); i++)
    {
        answer.push_back(nums[i]);
        solve(index + 1);
        answer.pop_back();
    }
}

int main(void)
{
    int num;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        // 중복되지 않게
        if (check[num] != 0) continue;
        nums.push_back(num);
        check[num] = 1;
    }

    // 사전 순으로 증가
    sort(nums.begin(), nums.end());

    solve(0);
}