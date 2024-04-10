#include <math.h>

using namespace std;

long long solution(int w,int h) {
    double lean = (double)h / w;
    long long count = 0;
    
    int max_divider = 1;
    int small = min(w, h);
    for(int i = 2; i <= small; ++i)
        if(h % i == 0 && w % i == 0)
            max_divider = i;
    int limit = w / max_divider;
    
    double cur = 0, next = 0;
    long long diff = 0;
    for(int i = 1; i <= limit; ++i)
    {
        next = lean * i;
        diff = (long long)next - (long long)cur;
        if(abs(next - (long long)next)) ++diff;
        
        count += diff;
        cur = next;
    }
    
    long long answer = (long long)w * h;
    return answer - (count * max_divider);
}