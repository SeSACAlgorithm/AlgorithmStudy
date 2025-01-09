#include <string>
#include <vector>
#include <algorithm>

int solution(vector<int> people, int limit) {
    int ans = 0;
    
    sort(people.begin(), people.end(), less<int>());    // 오름차순
    
    int light = 0, heavy = people.size() - 1;
    
    while(light <= heavy)
    {
        if(people[light] + people[heavy] <= limit)
            light++;    // 가벼운 사람만 태움
            
        heavy--;        // 항상 무거운 사람만 태움
        ans++;
    }
    
    return ans;
}
