#include <vector>
#include <algorithm>

using namespace std;

bool check_condition(vector<int>& rocks, int n, int distance, int target)
{
    int dist = 0, bef = 0;
    for(int i = 0; i <= rocks.size(); ++i)
    {
        if(i == 0)                 dist = rocks[0];
        else if(i == rocks.size()) dist = distance - bef;
        else                       dist = rocks[i] - bef;
        
        if(dist < target)
        {
            if(n == 0) return false;
            --n;
        }
        else
        {
            if(i == rocks.size()) break;
            bef =rocks[i];
        }
    }
    
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    int high = distance, low = 0;
    sort(rocks.begin(), rocks.end());
    
    int mid = 0;
    while(high > low)
    {
        mid = (high + low) / 2 + 1;
        if(check_condition(rocks, n, distance, mid))
            low = mid;
        else
            high = mid - 1;
    }
    
    return low;
}