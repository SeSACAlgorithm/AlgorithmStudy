#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;

    vector<int> records(N);
    for (int i = 0; i < N; ++i)
        cin >> records[i];

    int sum = 0;
    for (int i = 0; i < X; ++i)
        sum += records[i];
    int max = sum;
    int count = 1;

    for(int i = X; i < N; ++i)
    {
        sum = sum - records[i - X] + records[i];
        if (sum > max)
        {
            max = sum;
            count = 1;
        }
        else if (sum == max)
            ++count;
    }

    if (max == 0)
        cout << "SAD";
    else
        cout << max << "\n" << count;
}