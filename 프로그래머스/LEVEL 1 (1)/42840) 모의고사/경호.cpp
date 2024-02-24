#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> answer(3, 0);
    for(int i = 0; i < answers.size(); i++)
    {
        if(a[i % a.size()] == answers[i]) answer[0]++;
        if(b[i % b.size()] == answers[i]) answer[1]++;
        if(c[i % c.size()] == answers[i]) answer[2]++;
    }
    
    int max = *max_element(answer.begin(), answer.end());
    for(int i = 2; i >= 0; i--)
    {
        if(answer[i] < max)
            answer.erase(answer.begin() + i);
        else
            answer[i] = i + 1;
    }
        
    return answer;
}