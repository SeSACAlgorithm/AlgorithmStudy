#include <vector>

using namespace std;

vector<int> solution(int n) {
    int len = n * (n + 1) / 2;
    vector<int> answer(len, 0);
    
    int dir = 0; // 0: 좌하, 1: 우, 2: 좌상
    int floor = 1;
    int idx = 0;
    int count = 0;
    
    int next = 0;
    while(count < len)
    {
        answer[idx] = count + 1;
        switch(dir)
        {
            case 0:
                next = idx + floor;
                if(next >= len || answer[next] != 0)
                {
                    dir = 1;
                    ++idx;
                }
                else
                {
                    idx = next;
                    ++floor;
                }
                break;
            case 1:
                next = idx + 1;
                if(next >= len || answer[next] != 0)
                {
                    dir = 2;
                    idx -= floor;
                    --floor;
                }
                else
                {
                    idx = next;
                }
                break;
            case 2:
                next = idx - floor;
                if(next < 0 || answer[next] != 0)
                {
                    dir = 0;
                    idx += floor;
                    ++floor;
                }
                else
                {
                    idx = next;
                    --floor;
                }
                break;
        }
        ++count;
    }
    
    return answer;
}