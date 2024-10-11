#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> DP(N + 1, 1);
    for (int i = 2; i <= N; ++i)
        DP[i] = DP[i - 1] * i;

    cout << DP.back();
}