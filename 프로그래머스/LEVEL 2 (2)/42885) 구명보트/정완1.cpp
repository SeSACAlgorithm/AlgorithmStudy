#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int ans = 0;    // 구명보트 개수
    
    sort(people.begin(), people.end(), greater<int>()); // 내림차순 정렬
    
    int index = people.size() - 1;                      // 가장 가벼운 사람 index
    
    for(int i=0; i<people.size(); i++)
    {
        if(!people[i])              // 이미 탑승한 사람 체크
            break;
        
        if(people[i] + people[index] <= limit)  // 가장 무거운 사람 + 가장 가벼운사람
        {
            people[index] = 0;      // 가장 가벼운 사람 처리하면 0으로 표시
            index--;                // 그 다음으로 가벼운 사람
        }
        ans++;                      // 사용된 보트
    }
    
    return ans;
}
