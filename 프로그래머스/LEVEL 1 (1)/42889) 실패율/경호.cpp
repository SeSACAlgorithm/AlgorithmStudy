#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Failure
{
    int tryCount = 0;
    int failCount = 0;
    
    float GetRate() { return tryCount == 0 ? 0 : (float)failCount / tryCount; }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N, 0);
    for(int i = 0; i < N; i++)
        answer[i] = i + 1;
    
    map<int, Failure> m;
    for(int n : stages)
    {
        for(int i = 1; i <= n; i++)
            m[i].tryCount++;
        m[n].failCount++;
    }
    
    sort(answer.begin(), answer.end(), [&](int a, int b) { 
        if(m[a].GetRate() == m[b].GetRate())
            return a < b;
        else
            return m[a].GetRate() > m[b].GetRate(); }
        );
    return answer;
}