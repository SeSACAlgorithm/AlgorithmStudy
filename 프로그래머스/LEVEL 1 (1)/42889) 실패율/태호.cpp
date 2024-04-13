#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

constexpr double epsilon = 0.00000000001;

using namespace std;


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<int, double>> res;
    int num = stages.size();
    
    map<int, int> M;
    
    for(int i = 0; i < num; ++i)
        ++M[stages[i]];
    
    for(int i = 1; i <= N; ++i)
    {
        int k = M[i];        
        double f = (k == 0 || num == 0) ? 0.0 : (double)k / num;
       
        res.push_back({i, f});
        num -= k;
    }
    
    
    sort(res.begin(), res.end(), [](pair<int, double>& A, pair<int, double>& B)
    {
        
        if (abs(A.second - B.second) <= epsilon)
        {
            return A.first < B.first;
        }
        
        return A.second > B.second;
    });
    
    
    for(auto& iter : res)
        answer.push_back(iter.first);
    
    
    return answer;
}
