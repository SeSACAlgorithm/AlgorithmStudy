#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int W[11][11];
bool check[11] = {false, };

int answer = 987654321;

// 처음 시작한 위치, 현재 위치, 몇개의 마을 방문했는지, 합
void Solve(int start, int target, int index, int sum)
{
    if(index == N)
    {
        if(W[target][start] == 0) return;
        answer = min(sum + W[target][start], answer);
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        if(check[i] || W[target][i] == 0) continue;
        check[i] = true;
        Solve(start, i, index + 1, sum + W[target][i]);
        check[i] = false;
    }
}

void Input()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> W[i][j];
        }
    }
}

int main(void)
{
    Input();
    for(int i = 1 ; i <= N; i++)
    {
        check[i] = true;
        Solve(i, i, 1, 0);
        check[i] = false;
    }

    cout << answer << "\n";
}