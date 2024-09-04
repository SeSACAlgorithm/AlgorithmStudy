// 문제 분석
/*
    최소공배수 = 두수의 곱 / 최대공약수
*/

#include <iostream>

using namespace std;

int T;

// 유클리드 호제법
int solve(int A, int B)
{
    int temp;

    while(B != 0)
    {
        temp = A % B;
        A = B;
        B = temp;
    }

    return A;
}

int main(void)
{
    int A, B;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> A >> B;
        cout << A * B / solve(A, B) << "\n";
    }
}