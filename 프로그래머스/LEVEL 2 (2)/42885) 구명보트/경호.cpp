#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), [](int a, int b){
        return a > b;
    });
    
    int idx = people.size() - 1;
    for(int i = 0; i < people.size(); i++)
    {
        if(people[i] == 0) break;
        
        if(people[i] + people[idx] <= limit)
        {
            people[idx] = 0;
            idx--;
        }
        answer++;
    }
    
    return answer;
}