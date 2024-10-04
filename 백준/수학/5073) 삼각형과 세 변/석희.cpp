#include <iostream>
#include <algorithm>

using namespace std;

int find_max(int A, int B, int C)
{
    int maxNum = max(A, B);
    return max(maxNum, C);
}

int main(void)
{
    int A, B, C;

    while(true)
    {
        cin >> A >> B >> C;

        if(A == 0 && B == 0 && C == 0) return 0;

        int maxNum = find_max(A, B, C);

        if(maxNum >= ((A + B + C) - maxNum)) cout << "Invalid";         // 삼각형 조건 만족 X
        else if(A == B && B == C) cout << "Equilateral";                // 모두 같은 경우
        else if (A != B && B != C && A != C) cout << "Scalene";         // 모두 다른 경우
        else cout << "Isosceles";                                       // 그 외 (두 변의 길이만 같은 경우)

        cout << "\n";
    }
}