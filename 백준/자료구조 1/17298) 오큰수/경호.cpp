#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    stack<pair<int, int>> nums; // first: idx / second: value
    nums.emplace(-1, 1000001);
    vector<int> answer(N, -1);
    int temp;
    for(int i = 0; i < N; ++i)
    {
        cin >> temp;

        // 스택에서 현재 값보다 낮은 값을 만나면 현재값을 오큰수로 저장하고 제거
        while(nums.top().second < temp)
        {
            answer[nums.top().first] = temp;
            nums.pop();
        }

        // 현재 값을 스택에 추가
        nums.emplace(i, temp);
    }

    for(const int& ans : answer)
	cout << ans << " ";
}
