#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int arr[9];
int visit[9];

vector<int> vTemp;

int answer = 0;
void Input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void Solve(int index)
{
    if(index == N)
    {
        int sum = 0;
        for(int i = 0; i < vTemp.size() - 1; i++)
        {
            sum += (abs(vTemp[i] - vTemp[i + 1]));
        }
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(visit[i]) continue;

        vTemp.push_back(arr[i]);
        visit[i] = true;

        Solve(index + 1);

        vTemp.pop_back();
        visit[i] = false;
    }
}

int main(void)
{
    Input();
    Solve(0);

    cout << answer;
}