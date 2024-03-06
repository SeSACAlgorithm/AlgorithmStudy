#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    int high = max(n, m);
    int low = min(n, m);
    // 최대공약수
    for(int i = low; i > 0; i--)
    {
        if(low % i == 0 && high % i == 0)
        {
            answer[0] = i;
            break;
        }
    }
    // 최소공배수
    int limit = n * m;
    for(int i = high; i <= limit; i++)
    {
        if(i % high == 0 && i % low == 0)
        {
            answer[1] = i;
            break;
        }
    }
    
    return answer;
}