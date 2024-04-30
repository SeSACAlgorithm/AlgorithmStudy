#include <iostream>

using namespace std;

int main()
{
    int cow[11] = {-1, -1, -1, -1, -1, -1,-1, -1, -1, -1, -1};

    int N;
    cin >> N;

    int cowNum, position;
    int cnt = 0;

    for(int i=0; i<N; i++)
    {
        cin >> cowNum >> position;

        if(cow[cowNum] == -1)           // 소의 처음 위치(-1) 가 아닌 경우 처음 위치 set
            cow[cowNum] = position;

        else if(cow[cowNum] != -1 && cow[cowNum] != position) // 소의 위치가 다른 경우 cnt++
        {
            cow[cowNum] = position;
            cnt++;
        }
    }

    cout << cnt;
}