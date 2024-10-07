#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> nums(K);
    for (int i = 0; i < K; ++i)
        cin >> nums[i];

    int answer = 0;
    queue<int> que;
    for (int i = 0; i < K; ++i)
        que.push(nums[i]);

    while(false == que.empty())
    {
        int cur = que.front();
        que.pop();

        for (const int& num : nums)
        {
            // 현재 값의 끝에 num을 붙인 숫자가 N 이하라면 큐에 추가
            // 아니라면 현재 값과 answer를 비교하여 갱신
            int next = cur * 10 + num;
            if (next <= N)
                que.push(next);
            else
                answer = max(answer, cur);
        }
    }

    cout << answer;
}