#include <algorithm>
#include <numeric>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = accumulate(works.begin(), works.end(), answer);
    if(sum <= n) return 0;
    
    sort(works.begin(), works.end(), greater<int>());
    
    int idx = 0, next = 0;
    while(n > 0)
    {
        next = (idx + 1) % works.size();
        if(works[next] < works[0])
            idx = 0;
        else if(works[idx] < works[next])
            idx = next;
        
        --works[idx];
        --n;
    }
    
    answer = accumulate(works.begin(), works.end(), answer, [](long long a, long long b) 
                                                            {return a + pow(b, 2);});
    return answer;
}