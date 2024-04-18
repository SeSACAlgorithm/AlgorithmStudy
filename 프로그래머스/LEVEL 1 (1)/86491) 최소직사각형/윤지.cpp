#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i = 0 ; i < sizes.size(); i++){
        // 큰 순으로 재배치
        if(sizes[i][0] > sizes[i][1]){
            reverse(sizes[i].begin(), sizes[i].end());
        }
    }
    
    int x = sizes[0][0]; ;
    int y = sizes[0][1];
    for(int i = 0 ; i < sizes.size(); i++){
        x = max(x, sizes[i][0]);
        y = max(y, sizes[i][1]);
    }
    
    answer = x * y;
    
    
    return answer;
}
