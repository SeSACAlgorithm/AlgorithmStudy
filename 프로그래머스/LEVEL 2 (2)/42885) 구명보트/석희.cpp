#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int index = 0;
    
    sort(people.begin(), people.end(), less<int>());
    
    while(index < people.size())
    {  
        int last = people.back();
        people.pop_back();
        if(people[index] + last <= limit)
        {
            index++;
        }
        answer++;
    }

    return answer;
}