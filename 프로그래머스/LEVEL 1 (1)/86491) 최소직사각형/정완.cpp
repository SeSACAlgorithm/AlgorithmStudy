#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int ans = 0;

    vector<int> max1;
    vector<int> min1;
    
    for(vector<int> size : sizes)
    {
        max1.push_back(max(size[0], size[1]));
        min1.push_back(min(size[0], size[1]));
    }
    
    sort(max1.begin(), max1.end(), greater<int>());
    sort(min1.begin(), min1.end(), greater<int>());
    
    ans = max1.front() * min1.front();
    
    return ans;
}
