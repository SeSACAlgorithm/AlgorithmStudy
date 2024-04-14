#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0, max_h = 0;
    
    int w1 = 0, w2 = 0, h1 = 0, h2 = 0;
    int res1 = 0, res2 = 0;
    for(vector<int> vec : sizes)
    {
        w1 = vec[0] > max_w ? vec[0] : max_w;
        h1 = vec[1] > max_h ? vec[1] : max_h; 
        res1 = w1 * h1;
        
        w2 = vec[1] > max_w ? vec[1] : max_w; 
        h2 = vec[0] > max_h ? vec[0] : max_h; 
        res2 = w2 * h2;
        
        max_w = res1 < res2 ? w1 : w2;
        max_h = res1 < res2 ? h1 : h2;
    }
    
    return max_w * max_h;
}