#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string s;
    cin >> s;

    int rG = 0;         // 빨간색 색깔 그룹 개수
    int bG = 0;         // 파란색 색깔 그룹 개수

    char cur = s[0];    // 첫 번째 색깔

    if (cur == 'R')     // 첫 번째 색깔이 R 인 경우
        rG++;

    else                // 첫 번째 색깔이 B 인 경우
        bG++;

    for (int i = 1; i < N; i++) // 2번째 색깔부터 시작
    {
        if (s[i] != cur)
        {
            cur = s[i];

            if (cur == 'R')
                rG++;
            
            else 
                bG++;
        }
    }

    cout << min(rG, bG) + 1;
}
