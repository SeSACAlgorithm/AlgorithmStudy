#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
        numbers[i] = i + 1;

    vector<int> answer;
    int idx = 0, count = 0;
    while (answer.size() < N)
    {
        if (numbers[idx] == -1)
        {
            idx = (idx + 1) % N;
            continue;
        }

        count++;
        if (count == K)
        {
            answer.push_back(numbers[idx]);
            numbers[idx] = -1;
            count = 0;
        }
        idx = (idx + 1) % N;
    }

    // 출력
    cout << "<";
    for (int i = 0; i < answer.size() - 1; i++)
        cout << answer[i] << ", ";

    cout << answer.back() << ">";
}