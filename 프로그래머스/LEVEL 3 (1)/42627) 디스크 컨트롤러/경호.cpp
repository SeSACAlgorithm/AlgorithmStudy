#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp{
  bool operator()(vector<int> a, vector<int> b)
  {
      return a[1] > b[1];
  }
};

int solution(vector<vector<int>> jobs) {
    long long answer = 0;
    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    long long cur = 0;
    int idx = 0;
    int count = 0;
    while(count < jobs.size())
    {
        for(int i = idx; i < jobs.size(); ++i)
        {
            if(jobs[i][0] > cur) break;

            pq.push(jobs[i]);
            ++idx;
        }
        
        if(pq.empty())
        {
            cur = jobs[idx][0];
            continue;
        }
        
        vector<int> cur_job = pq.top();
        pq.pop();
        
        cur += cur_job[1];
        answer += cur - cur_job[0];   
        ++count;
    }
    
    return answer / jobs.size();
}