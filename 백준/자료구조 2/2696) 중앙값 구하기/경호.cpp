#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> inputs(N);
    for(int idx = 0; idx < N; ++idx)
    {
        int len;
        cin >> len;

        inputs[idx].resize(len);
        for(int i = 0; i < len; ++i)
            cin >> inputs[idx][i];
    }

    for (int idx = 0; idx < N; ++idx)
    {
        // 자동 정렬을 위한 우선순위 큐와 빼놓은 값을 임시 저장해둘 큐 선언
        priority_queue<int> pq;
        queue<int> que;

        const int len = static_cast<int>(inputs[idx].size());
        // 출력할 중앙값 개수 출력
        const int odds = (len & 1) == 1 ? len / 2 + 1 : len / 2;
        cout << odds << "\n";

        int count = 0;
        for (int i = 0; i < len; ++i)
        {
            pq.push(inputs[idx][i]);
            if ((i & 1) == 1)
                continue;

            // 중앙값에 도달할 때까지 우선순위 큐의 원소를 큐에 저장하고 제거 
            int half = pq.size() / 2 + 1;
            while (pq.size() > half)
            {
                que.push(pq.top());
                pq.pop();
            }
            // 중앙값 출력 및 출력 수 카운팅
            // 10번째 출력이었다면 줄바꿈
            cout << pq.top() << " ";
            if (++count == 10)
            {
                count = 0;
                cout << "\n";
            }
            // 큐에 임시로 저장한 값들 다시 복원
            // 힙 트리의 원소 입력 방식 특성상 스택보다 큐가 살짝 빠름
            while (false == que.empty())
            {
                pq.push(que.front());
                que.pop();
            }
        }
        // 중간값을 출력하던 도중이었다면 줄바꿈
        if (count > 0)
            cout << "\n";
    }
}