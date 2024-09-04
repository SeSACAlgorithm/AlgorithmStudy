#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 초기 N개만큼 우선순위 큐에 저장
    priority_queue<int, vector<int>, greater<int>> pq;
    int temp;
    for(int i = 0 ; i < N; ++i)
    {
        cin >> temp;
        pq.push(temp);
    }
    // 이후로는 큐의 가장 작은 숫자보다 큰 경우에만 push & pop
    int limit = N * N;
    for(int i = N; i < limit; ++i)
    {
        cin >> temp;
        if(pq.top() < temp)
        {
            pq.push(temp);
            pq.pop();
        }
    }

    cout << pq.top();
}