// 문제 분석
/*
    열린 괄호가 나오면 스택에 담고
    닫힌 괄호가 나오면 쌍인 괄호는 빼고
    스택에 담겨있는 나머지 개수 anwer에 더하기

    * 고려할 사항 *
    1. 닫힌 괄호만 나오는 경우가 있나?
        -> 레이저는 항상 ()으로 표현, 쇠막대기의 왼쪽과 오른쪽은 각각 (, )으로 표현
        즉, 닫힌 괄호만 나오는 경우는 없음
    2. 입력은 총 얼마나 들어오는지?
    -> 안알려줌. string으로 한번에 받아서 하나하나 확인하는 방식으로 풀어야 할듯
    3. 막대의 끝인 경우?
    -> 이때는 레이저가 아니라서 자르는게 아님! 즉, 스택에 담겨있는 모든것을 더하면 안됨
    -> 다만 막대 한개를 자르는 것과 같은 상황이므로 1을 추가해줘야함.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> s_bar;

int solve(string _allBar)
{
    int answer = 0;
    
    for(int i = 0; i < _allBar.size(); i++)
    {
        if(_allBar[i] == '(') s_bar.push('(');
        else if(_allBar[i] == ')')
        {
            s_bar.pop();

            if(_allBar[i-1] == '(') answer += s_bar.size();            // 레이저인 경우
            else answer++;                                             // 막대가 끝난 경우
        }
    }

    return answer;
}

int main(void)
{
    string allBar;
    cin >> allBar;

    cout << solve(allBar);
}