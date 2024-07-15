#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; ++i)
        cin >> nums[i];

    int idx = 0;
    int move = 0;
    for(int i = 0; i < N; ++i)
    {
        while(move != 0)
        {
            idx = move > 0 ? (idx + 1) % N : (idx - 1 + N) % N;
            if (nums[idx] == 0) continue;
            move = move > 0 ? move - 1 : move + 1;
        }

        cout << idx + 1 << " ";
        move = nums[idx];
        nums[idx] = 0;
    }
}