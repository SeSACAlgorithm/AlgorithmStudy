#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    for(int i = 0; i < citations.size(); i++)
    {
        if(citations[i] > citations.size() - i)
        {
            if(citations.size() - i > answer)
                answer = citations.size() - i;
            break;
        }
        
        answer = citations[i];
    }
    
    return answer;
}