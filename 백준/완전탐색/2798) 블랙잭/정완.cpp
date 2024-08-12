#include "iostream"

using namespace std;

    int N, M;
    int Card[101];

int input()
{
    cin >> N >> M;

    for(int i=0; i<N; i++)
        cin >> Card[i];
}

int solve() // 최대 합
{
    int sum = 0;        // 현재 카드 조합의 합
    int result = 0;     // 조건 만족하는 최대 합

    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            for(int k=j+1; k<N; k++)
            {
                sum = Card[i] + Card[j] + Card[k];  // 현재 카드 3장 비교

                if(sum <= M && result < sum)    // result로 계속 비교
                    result = sum;
            }
        }
    }

    return result;
}

int main(void)
{
    input();
    cout << solve();
}