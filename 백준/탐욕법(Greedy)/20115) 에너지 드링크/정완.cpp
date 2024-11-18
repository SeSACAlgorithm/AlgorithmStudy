#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    float e[100001];        // 정수형 X, 실수형 O       float 나 double 사용
    float max = 0;

    for(int i=0; i<N; i++)
        cin >> e[i];

    sort(e, e + N);

    max = e[N-1];

    for(int i=0; i<N-1; i++)
        max += (e[i] / 2);

    cout << max;
}