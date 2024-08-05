// 문제 분석
/*
    - 중복 불가 (만약 중복되었다면 나중에 나온 순서로 갱신)
    - FIFO

    - 주의할 점
    1. 8자리 고정 (앞에 0이 나온 경우에 0 포함해서 출력해야 함)
    2. 만약 최대 수강 인원(K)보다 학생의 수가 더 작은 경우엔 학생의 수만큼만 출력해야 함
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int K, L;
map<int, int> m_list;   // 학생, 신청 순서

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void input()
{
    int num;

    cin >> K >> L;

    for(int i = 0; i < L; i++)
    {
        cin >> num;
        m_list[num] = i;
    }
}

void solve()
{
    vector<pair<int, int>> v_list(m_list.begin(), m_list.end());
    sort(v_list.begin(), v_list.end(), comp);

    for(int i = 0; i < min((int)v_list.size(), K); i++)
    {
        // 자리수 지정
        cout.width(8);
        cout.fill('0');
        cout << v_list[i].first << "\n"; 
    }
}

int main(void)
{
    input();
    solve();
}