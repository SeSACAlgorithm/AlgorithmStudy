#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, K = 0;
    cin >> N >> K;

    vector<int> nums(N + 1, 0);
    for (int i = 0; i <= N; i++)
        nums[i] = i;

    bool isOver = false;
    for (int i = 2; i <= N; i++)
    {
        if (nums[i] == -1) continue;

        int limit = N / i;
        for (int j = 1; j <= limit; j++)
        {
            if (nums[i * j] == -1) continue;

            if (K == 1)
            {
                cout << nums[i * j] << '\n';
                isOver = true;
                break;
            }
            nums[i * j] = -1;
            K--;
        }
        if (isOver) break;
    }
}