#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int x = 0;
    int y = 0;
    // 가로와 세로 비교, 더 긴 길이 0번째로 보내
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            //swap 변수 두 개의 순서를 바꿔준다!
            swap(sizes[i][0], sizes[i][1]);
        }
        // 배열 중 가장 큰 값을 찾자~
        x = max(x, sizes[i][0]);
        y = max(y, sizes[i][1]);

        // 한 방에 끝내는 방법도 있었네!!
        // 작은 수 중에서 최대값, 큰 수 중에서 최대값 찾아서 곱하는
       /* x = max(x, min(sizes[i][0], sizes[i][1]));
        y = max(y, max(sizes[i][0], sizes[i][1]));*/

        answer = x * y;
    }
    // 0번째에서 가장 큰 수 1번째에서 가장 큰 수 곱하기
    return answer;
}