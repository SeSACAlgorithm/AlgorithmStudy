#include <iostream>

using namespace std;

int N, M, K;
int arr[301][301];

int CalcSum(int i, int j, int x, int y)
{
    int sum = 0;
    for(int indexX = i; indexX <= x; indexX++)
    {
        for(int indexY = j; indexY <= y; indexY++)
        {
            sum += arr[indexX][indexY];
        }
    }

    return sum;
}

void Solve()
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> K;
    int i, j, x, y;
    for(int index = 0; index < K; index++)
    {
        cin >> i >> j >> x >> y;
        cout << CalcSum(i, j, x, y) << "\n";
    }
}

int main(void)
{
    Solve();
}