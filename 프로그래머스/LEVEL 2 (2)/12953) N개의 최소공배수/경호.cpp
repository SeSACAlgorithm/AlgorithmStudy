#include <vector>
#include <math.h>

using namespace std;

int get_lcm(int a, int b)
{
    int temp = max(a ,b);
    int devider = min(a ,b);
    int remain = -1;
    while(remain != 0)
    {
        remain = temp % devider;
        if(remain > 0)
        {
            temp = devider;
            devider = remain;
        }
    }
    
    return devider * (a / devider) * (b / devider);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); ++i)
        answer = get_lcm(answer, arr[i]);
    
    return answer;
}