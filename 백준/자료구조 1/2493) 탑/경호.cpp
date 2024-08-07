#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;

    stack<pair<int, int>> lasers; // first: height / second: number
    vector<int> answer(N, 0);
    int temp;
	for(int i = 0; i < N; ++i)
    {
        cin >> temp;

        // 스택이 비어있다면 추가 후 스킵
		if(lasers.empty())
		{
            lasers.emplace(temp, i + 1);
            continue;
	    }
        // 스택에서 현재 만난 건물 높이보다 낮은 건물은 모두 제거
        while(false == lasers.empty() && lasers.top().first < temp)
            lasers.pop();
        // 스택에 값이 남아있다면 해당 건물의 번호를 저장하고, 이후 현재 빌딩 스택에 추가
        if(false == lasers.empty())
			answer[i] = lasers.top().second;
        lasers.emplace(temp, i + 1);
    }

    for(const int& ans : answer)
		cout << ans << " ";
}