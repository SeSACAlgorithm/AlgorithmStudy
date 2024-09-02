#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> time(N);
    for (int i = 0; i < N; ++i)
        cin >> time[i].first >> time[i].second;
    // 시작 시간 순(같다면 종료 시간 순)으로 오름차순 정렬
    sort(time.begin(), time.end());

    // 가장 빠른 종료 시간 순서로 정렬하기 위한 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> end_que;
    for(int i = 0; i < time.size(); ++i)
    {
        end_que.push(time[i].second);
        // 가장 빠른 종료시간이 현재 수업의 시작 시간 이하라면 강의실이 추가로 필요하지 않음
        // => 큐에서 제거
        if (end_que.top() <= time[i].first)
            end_que.pop();
    }
    // 큐의 남은 사이즈 => 총 필요한 강의실 수
    cout << end_que.size();
}