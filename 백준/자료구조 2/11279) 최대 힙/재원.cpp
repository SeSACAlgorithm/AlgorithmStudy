#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);  // 입출력 최적화
    cin.tie(NULL);  // cin과 cout의 동기화 끊기

    int count;
    cin >> count;
    int input;
    priority_queue<int> q;
    vector<int> v;

    for (int i = 0; i < count; i++)
    {
        cin >> input;
        if (input == 0)
        {
            if (q.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(q.top());
                q.pop();
            }
        }
        else
        {
            q.push(input);
        }
    }

    // 결과를 한 번에 출력
    for (auto a : v)
        cout << a << '\n';

    return 0;
}
