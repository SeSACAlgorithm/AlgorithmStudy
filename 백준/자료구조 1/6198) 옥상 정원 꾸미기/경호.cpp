#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> buildings(N);
    for (int i = 0; i < N; ++i)
        cin >> buildings[i];

    stack<int> taller;
    long long answer = 0;
    for(int i = 0; i < N; ++i)
    {
        // 스택이 비어있다면 추가 후 스킵
	if(taller.empty())
	{
	    taller.push(buildings[i]);
            continue;
	}
        // 스택에서 현재 만난 건물 높이 이하의 빌딩은 모두 제거
        while(false == taller.empty() && taller.top() <= buildings[i])
            taller.pop();
        // 스택에 남아있는 건물 수 만큼 결과 값 증가, 이후 현재 빌딩 스택에 추가
        answer += taller.size();
        taller.push(buildings[i]);
    }

    cout << answer;
}
