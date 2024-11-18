#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    float v[100001];        // 정수형 X, 실수형 O       float 나 double 사용
    float max = 0;

    for(int i=0; i<N; i++)
        cin >> v[i];

    sort(v, v + N);

    max = v[N-1];

    for(int i=0; i<N-1; i++)
        max += (v[i] / 2);

    cout << max;
}