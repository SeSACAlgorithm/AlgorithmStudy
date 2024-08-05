#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    queue<int> nums;
    for (int i = 0; i < N; ++i)
        nums.push(i + 1);

    vector<int> answer;
    int count = 0;
    while(false == nums.empty())
    {
        ++count;
        if(count == K)
        {
            count = 0;
            answer.emplace_back(nums.front());
        }
        else
        {
            nums.push(nums.front());
        }
        nums.pop();
    }

    cout << "<";
    for (int i = 0; i < N - 1; ++i)
        cout << answer[i] << ", ";
    cout << answer.back() << ">";
}