#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 소수 판별 함수(에라토스테네스의 체)
bool is_prime(const int num)
{
    const int limit = static_cast<int>(sqrt(num));
    for(int i = 2; i <= limit; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool check_condition(const int value, const int& M)
{
    // 서로 다른 두 소수의 합으로 표현 가능한가
    // 골드 바흐 추측을 이용해 계산량 감소(4보다 큰 짝수는 두 소수의 합으로 표현할 수 있다)
    // 홀수인 경우, 짝수 + 홀수로만 표현 가능하므로 소수 중 유일한 짝수인 2와 value - 2가 소수인 경우만 조건 만족
    // 짝수인 경우 4보다 크다면 모두 소수의 합으로 표현 가능하지만 골드 바흐 추측은 중복을 허용
    // => 2로 나눈 값이 소수라면 골드 바흐 추측만으로 완벽하게 판단할 수 없음(ex. 14 = 3 + 11 = 7 + 7)
    //  => 짝수 중 2로 나눈 값이 소수인 경우만 모든 케이스를 검사
    if (value < 5)
        return false;

    if((value & 1) == 1 && false == is_prime(value - 2))
        return false;

    if ((value & 1) == 0 && is_prime(value / 2))
    {
        int small = 2, big = value - 2;
        bool sum_prime = false;
        while (big > small)
        {
            if (is_prime(big) && is_prime(small))
            {
                sum_prime = true;
                break;
            }
            --big;
            ++small;
        }
        if (false == sum_prime)
            return false;
    }

    // 두 소수의 곱으로 표현 가능한가
    // M으로 나눠지지 않을 때까지 나누고 시작
    // 제곱근 이하의 숫자와 제곱근 이상의 숫자의 곱으로 구성되므로 제곱근까지만 검사
    int cur = value;
    while (cur % M == 0)
        cur = cur / M;

    const int limit = static_cast<int>(sqrt(cur));
    for(int i = 2; i <= limit; ++i)
    {
        if (cur % i > 0)
            continue;

        int divided = cur / i;
        if (is_prime(i) && is_prime(divided))
            return true;
    }
    return false;
}

void back_tracking(const int value, vector<bool>& used, const int count, const int& K, const int& M, int& answer)
{
    // K개의 숫자를 뽑아 만든 수라면 조건 검사 후 카운팅
	if(count == K)
	{
        if (check_condition(value, M))
            ++answer;
        return;
	}

    for(int i = 0; i < 10; ++i)
    {
        // 맨 첫 자리에는 0이 올 수 없으므로 스킵
        if (i == 0 && count == 0)
            continue;

        if (used[i])
            continue;

        used[i] = true;
        back_tracking(value * 10 + i, used, count + 1, K, M, answer);
        used[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int K, M;
    cin >> K >> M;

    vector<bool> used(10, false);
    int answer = 0;
    back_tracking(0, used, 0, K, M, answer);

    cout << answer;
}