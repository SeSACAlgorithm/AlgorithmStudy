#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int len = w * 2 + 1;
    
    // 좌측 체크
    int left = stations[0] - w - 1;
    if(left > 0)
    {
        answer += left / len;
        if(left % len > 0) ++answer;
    }
    // 우측 체크
    int right = n - stations.back() - w;
    if(right > 0)
    {
        answer += right / len;
        if(right % len > 0) ++answer;
    }
    // 기지국 사이 체크
    int gap = 0;
    for(int i = 1; i < stations.size(); ++i)
    {
        gap = stations[i] - stations[i - 1] - len;
        answer += gap / len;
        if(gap % len > 0) ++answer;
    }

    return answer;
}