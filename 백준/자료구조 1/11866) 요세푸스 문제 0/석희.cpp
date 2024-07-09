// 문제 분석
/*
    1~N까지 큐에 넣기
    큐를 돌면서 i를 계속 증가
    i가 K와 같아진 순간 제거!
    안같을때는 맨 앞에꺼 빼서 맨뒤에 넣기
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
queue<int> person;
vector<int> answer;

void solve()
{
    int i = 0;
    while (!person.empty())
    {
        i++;
        if (i == K)
        {
            i = 0;
            answer.push_back(person.front());
        }
        else
        {
            person.push(person.front());
        }
        person.pop();
    }
}

int main(void)
{
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        person.push(i);
    }

    solve();

    cout << "<";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ((i != N - 1) ? ", " : ">");
    }
}