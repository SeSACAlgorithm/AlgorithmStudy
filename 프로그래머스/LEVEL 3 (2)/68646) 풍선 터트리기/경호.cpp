#include <math.h>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    vector<int> left(a.size());
    vector<int> right(a.size());
    
    left[0] = a[0];
    for(int i = 1; i < a.size(); ++i)
        left[i] = min(left[i - 1], a[i]);
    
    right[a.size() - 1] = a.back();
    for(int i = a.size() - 2; i >= 0; --i)
        right[i] = min(right[i + 1], a[i]);
    
    int answer = 2;
    int limit = a.size() - 1;
    bool left_small = false, right_small = false;
    for(int i = 1; i < limit; ++i)
    {
        left_small = left[i - 1] < a[i];
        right_small = right[i + 1] < a[i];
        if(left_small && right_small) continue;
        
        ++answer;
    }
        
    return answer;
}