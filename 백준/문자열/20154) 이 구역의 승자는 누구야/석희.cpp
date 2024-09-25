// 문제 분석
/*
    1. 각 문자의 횟수로 문자 변환
    2. 횟수들을 가지고 앞에서부터 두개씩 더해감
    3. 짝 X -> 다시 앞에서부터 더해감
    4. 마지막에 남은 수가 홀수라면 이기는 것
    (더한 값이 10을 넘으면 10으로 나눈 나머지로 바꿔줌)

    => 덧셈 연산은 누가 먼저 더하든 상관없음 -> 그냥 더하면서 10 넘어가면 10으로 나누기
*/

#include <iostream>

using namespace std;

int alphabet_nums[26] = {3, 2, 1, 2, 3, 3, 3, 3,
                         1, 1, 3, 1, 3, 3, 1, 2,
                         2, 2, 1, 2, 1, 1, 2, 2,
                         2, 1};

int main(void)
{
    string str;
    cin >> str;

    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum += alphabet_nums[str[i] - 'A'];
        if (sum > 9)
            sum = sum % 10;
    }

    cout << (sum % 2 ? "I'm a winner!" : "You're the winner?");
}