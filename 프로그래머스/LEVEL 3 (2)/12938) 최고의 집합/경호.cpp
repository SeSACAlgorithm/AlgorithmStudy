#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s < n) return vector<int>{ -1 };
    
    vector<int> answer(n, s / n);
    int remain = s % n;
    
    while(remain > 0)
    {
        int idx = n - 1;
        while(remain > 0)
        {
            ++answer[idx];
            --remain;
            --idx;
        }
    }
    
    return answer;
}