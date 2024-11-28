/*
I. 2를 곱한다.
II. 1을 수의 가장 오른쪽에 추가한다.
*/

#include<iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    int result = 1;     // 최솟값에 1을 더한 값 --> 처음 시작 값을 1로

    while (true)
    {
        if(A == B)
            break;
        
        else if(A > B)
        {
            result = -1;
            break;
        }

        if(B % 2 == 0)
            B /= 2;

        else if(B % 10 == 1)
            B = (B-1) / 10;
        
        else
        {
            result = -1;
            break;
        }

        result++;
    }

    cout << result;    
}