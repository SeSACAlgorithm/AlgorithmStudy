#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

#define MAX 10000000 // N의 최대값보다 크게 설정(10배)

int main()
{
    int N;
    cin >> N;

    int answer = 0;

    // 에라토스 테네스의 체로 소수만 남기기
    vector<int> nums(MAX + 1, 0);
    int limit = sqrt(MAX);
    for(int i = 2; i <= limit; ++i)
        for (int j = i * i; j <= MAX; j += i)
            nums[j] = -1;

    vector<int> primes;
    for(int i = 2; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
            primes.push_back(i);
    }

    int start = 0;
    for(int i = 0; i < primes.size(); ++i)
    {
        // N보다 작다면 패스
        if (primes[i] < N) continue;
        // 팰린드롬인지 검사
        string s = to_string(primes[i]);
        int left = 0, right = s.size() - 1;
        bool is_palin = true;
        while(left < right)
        {
            if (s[left] != s[right])
            {
                is_palin = false;
                break;
            }
            ++left;
            --right;
        }

        if (is_palin)
        {
            answer = primes[i];
            break;
        }
    }

    cout << answer;
}