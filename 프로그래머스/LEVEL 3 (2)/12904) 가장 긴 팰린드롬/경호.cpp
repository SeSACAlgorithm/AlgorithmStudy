#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 0;

    // 마나커 알고리즘은 기본적으로 홀수 길이 기반
    // 짝수인 경우를 체크하기 위해 더미 문자 삽입
    string extended = "#";
    for(const char& c : s)
    {
        extended += c;
        extended += "#";
    }

    vector<int> DP(extended.size(), 0);
    int c = 0, r = 0;
    for(int i = 0; i < extended.size(); ++i)
    {
        // 최대 팰린드롬 안이라면 초기값 설정
        // 이미 계산된 범위를 넘어갔다면 0으로 초기화
        DP[i] = r < i ? 0 : min(DP[2 * c - i], r - i);

        // 조건 1. 현재 위치에서 확장해도 좌측 끝을 넘어가지 않는가
        // 조건 2. 현재 위치에서 확장해도 우측 끝을 넘어가지 않는가
        // 조건 3. 좌측과 우측의 문자가 같은가
        while(i - DP[i] - 1 >= 0 && i + DP[i] + 1 < extended.size() 
              && extended[i - DP[i] - 1] == extended[i + DP[i] + 1])
            ++DP[i];

        // 현재 위치 기준 최대 팰린드롬의 오른쪽 끝이 r을 넘어갔다면 갱신
        if(DP[i] + i > r)
        {
            r = DP[i] + i;
            c = i;
        }
    }

    return *max_element(DP.begin(), DP.end());
}