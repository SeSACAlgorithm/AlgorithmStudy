#include <iostream>
#include <vector>

using namespace std;

int N, M;
int preference[30][30];
vector<int> chicken;
int answer = 0;

void Input()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> preference[i][j];
        }
    }
}

void Solve(int index, int now)
{
    if(index == 3)
    {
        int temp = 0;
        for(int i = 0; i < N; i++)
        {
            int maxPreference = 0;
            for(int j = 0; j < chicken.size(); j++)
            {
                maxPreference = max(maxPreference, preference[i][chicken[j]]);
            }
            temp += maxPreference;
        }
        answer = max(answer, temp);
        return;
    }

    for(int i = now; i < M; i++)
    {
        chicken.push_back(i);
        Solve(index + 1, i + 1);
        chicken.pop_back();
    }
}

int main(void)
{
    Input();
    Solve(0, 0);
    cout << answer;
}