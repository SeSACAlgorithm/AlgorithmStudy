#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0, y = 0;
    
    for(int i = 0; i < sizes.size(); ++i)
        if(sizes[i][0] < sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);
    
     for(int i = 0; i < sizes.size(); ++i)
     {
         x = max(x, sizes[i][0]);
         y = max(y, sizes[i][1]);
     }
    
    return x * y;
}
