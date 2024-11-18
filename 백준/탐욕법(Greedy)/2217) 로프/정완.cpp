#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int rope[100000];

int main()
{
    int N;
    int cur;
    int max;

    cin >> N;

    for(int i=0; i<N; i++)
        cin >> rope[i];

    sort(rope, rope + N);

    max = rope[N-1];

    for(int i=N-1; i>=0; i--)
    {
        cur = rope[i] * (N - i);

        if(max < cur)
            max = cur;
    }

    cout << max;

    return 0;
}