#include <iostream>
#include <deque>

using namespace std;

int N, M;
int order[51];
deque<int> dq;
int answer = 0;

void Input()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> order[i];
    }
}

int FindPos(int target)
{
    deque<int> dTemp;
    dTemp = dq;
    int pos = 0;
    while (!dTemp.empty())
    {
        int front = dTemp.front();
        dTemp.pop_front();
        pos++;

        if (front == target)
            return pos;
    }
    return pos;
}

void popFront()
{
    int front = dq.front();
    dq.pop_front();
    dq.push_back(front);
}

void popBack()
{
    int back = dq.back();
    dq.pop_back();
    dq.push_front(back);
}

void Solve()
{
    int index = 0;
    int target = order[index];
    while (index < M)
    {
        int pos = FindPos(target) - 1;

        // 앞이랑 더 가까우면
        if (pos < dq.size() - pos)
        {
            while (pos > 0)
            {
                popFront();
                pos--;
                answer++;
            }
        }
        else
        {
            pos = dq.size() - pos;
            while (pos > 0)
            {
                pos--;
                popBack();
                answer++;
            }
        }

        target = order[++index];
        dq.pop_front();
    }

    cout << answer;
}

int main(void)
{
    Input();
    Solve();
}
