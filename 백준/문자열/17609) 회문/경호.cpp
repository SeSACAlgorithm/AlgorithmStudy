#include <iostream>
#include <vector>
#include <string>

using namespace std;

// state - 0: 회문 / 1: 유사 회문 / 2: 그 외
int is_palindrome(const string& input, int state, int left, int right)
{
    while (left < right)
    {
        // 양쪽 끝이 동일하다면 좌표 이동 후 검사 계속 진행
        if (input[left] == input[right])
        {
            ++left;
            --right;
            continue;
        }

        // 아직까지는 회문이었는데 양 끝이 안맞는 경우
		// 한 글자를 건너뛰었을 때 회문이 유지된다면 상태를 유사 회문으로 변경하고 계속 진행
        // 불가능하다면, 일반 문자열로 판정
        if (state == 0)
        {
            // 짝수 길이 문자열이고, 현재 검사하는 대상이 가운데 2글자라면 1개를 지우면 홀수 길이 회문이 됨
            if (right - left == 1)
            {
                state = 1;
                break;
            }
            // 왼쪽 문자를 제거했다고 가정하고 실행
            // 결과가 1이라면 유사 회문이 가능하므로 검사 종료
            if (left + 1 < right && input[left + 1] == input[right])
            {
                if(is_palindrome(input, 1, left + 1, right) == 1)
                {
                    state = 1;
                    break;
                }
            }
            // 오른쪽 문자를 제거했다고 가정하고 실행
            // 결과가 1이라면 유사 회문이 가능하므로 검사 종료
            if(right - 1 > left && input[left] == input[right - 1])
            {
                if (is_palindrome(input, 1, left, right - 1) == 1)
                {
                    state = 1;
                    break;
                }
            }
            // 둘 다 만족하지 않는다면 유사 회문도 불가능 => 일반 문자열로 판정
            state = 2;
            break;
        }

        // 이미 유사 회문인데 양 끝이 동일하지 않다면 일반 문자열로 판정
        if (state == 1)
        {
            state = 2;
            break;
        }
    }

    return state;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> answer(N);

    string input;
    for(int i = 0; i < N; ++i)
    {
        cin >> input;
        answer[i] = is_palindrome(input, 0, 0, input.size() - 1);
    }

    for (const int& n : answer)
        cout << n << "\n";
}