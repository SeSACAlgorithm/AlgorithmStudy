#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> lastLoc(11, -1); // 각 소의 마지막 위치를 저장하는 배열 -1로 초기화
    int count = 0; // 위치가 변한 횟수

    for (int i = 0; i < N; i++)
    {
        int cowNum, position;
        cin >> cowNum >> position; 

        // 만약 처음으로 관찰된 소라면, 위치를 저장하고 넘어감
        if (lastLoc[cowNum] == -1)
        {
            lastLoc[cowNum] = position;
        }
        // 이미 관찰된 소가 이전 위치와 다른 위치에 있다면, 위치 변화를 카운트하고 새 위치로 업데이트
        else if (lastLoc[cowNum] != position)
        {
            lastLoc[cowNum] = position;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
