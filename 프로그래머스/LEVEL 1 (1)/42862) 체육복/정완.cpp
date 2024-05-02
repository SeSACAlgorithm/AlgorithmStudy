#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int ans = 0;
    vector<int> tmp(n,1);   // 모든 학생에게 체육복 1개씩 할당
    
    for(int i : reserve)    // 여벌체육복 +1개
        tmp[i-1]++;
    
    for(int i : lost)       // 잃어버림 -1개
        tmp[i-1]--;
    
    for(int i=0; i<tmp.size(); i++)
    {
        if(tmp[i] == 0)     // 체육복 없는 사람이라면
            
            if(tmp[i-1] == 2)       // 앞사람 2벌이면
            {
                tmp[i]++;
                tmp[i-1]--;
            }
            
            else if(tmp[i+1] == 2)  // 뒷사람 2벌이면
            {
                tmp[i]++;
                tmp[i+1]--;
            }
    }
    
    for(int i=0; i<tmp.size(); i++) // 체육복 1벌 이상 카운트
        if(tmp[i] > 0)
            ans ++;
    
    return ans;
}
