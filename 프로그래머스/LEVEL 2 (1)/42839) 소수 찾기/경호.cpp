#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

void dfs(string num, string cur, vector<bool>& used, map<int, bool>& exist, vector<int>& result)
{
    if(cur.size() > 0)
    {
        int curNum = stoi(cur);
        if(false == exist[curNum])
        {
            exist[curNum] = true;
            result.push_back(curNum);
        }
    }
    
    for(int i = 0; i < num.size(); i++)
    {
        if(used[i]) continue;
        
        used[i] = true;
        dfs(num, cur + num[i], used, exist, result);
        used[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.size();
    
    vector<bool> used(numbers.size(), false);
    map<int, bool> exist;
    vector<int> result;
    dfs(numbers, "", used, exist, result);
    
    // 소수 체크
    for(int n : result)
    {
        if(n < 2) continue;
        
        bool isPrime = true;
        int limit = sqrt(n);
        for(int i = 2; i <= limit; i++)
        {
            if(n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            answer++;
    }
    
    return answer;
}