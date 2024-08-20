// 문제 분석
/*
 1~49에서 수 6개 고르기
 49가지 수 중 K개를 골라 집합 S를 만들고 그 수만 가지고 번호 선택

 * 입력 *
 K (6~13) / S에 포함되는 수들(K개)(오름차순)
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K;
int S[13];
int lotto[13];

void output(int index, int now)
{
    if(index == 6)
    {
        for(int i = 0; i < 6; i++)
        {
            cout << lotto[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = now; i < K; i++)
    {
        lotto[index] = S[i];
        output(index + 1, i + 1);
    }
}

int main(void)
{
    while(true)
    {
        cin >> K;
        if(K == 0) return 0;

        memset(lotto, 0, sizeof(lotto));
        for(int i = 0; i < K; i++)
        {
            cin >> S[i];
        }

        output(0, 0);
        cout << "\n";
    }
}