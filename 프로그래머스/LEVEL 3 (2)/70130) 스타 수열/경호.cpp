#include <vector>
#include <map>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n = static_cast<int>(a.size());
    
    map<int, int> count; // 카운팅용 map
    map<int, int> last_idx; // 같은 집합으로 묶은 마지막 원소 인덱스
    // 집합을 순회하며 원소마다 자신을 교집합으로 하는 스타 수열을 만들 수 있는지 카운팅
    for(int i = 0; i < n; ++i)
    {
        // 좌측에 원소가 있고 현재 원소와 다른지 체크
        // 좌측 원소가 이미 같은 원소의 수열에 쓰였을 수 있으므로, 마지막 인덱스보다 큰 지 체크
        // 단, last_idx에 저장된 값이 없는 경우 0번 인덱스와 구분이 안되므로 count로 추가 검사
        if(i > 0 && a[i - 1] != a[i] && (count[a[i]] == 0 || i - 1 > last_idx[a[i]]))
        {
            ++count[a[i]];
            last_idx[a[i]] = i - 1;
        }  
        // 우측에 원소가 있고 현재 원소와 다르다면 카운팅
        else if(i + 1 < n && a[i + 1] != a[i])
        {
            ++count[a[i]];
            last_idx[a[i]] = i + 1;
        } 
    }
    // 카운팅한 원소 중 최대값 찾기
    for(auto it = count.begin(); it != count.end(); ++it)
        if(answer < it->second)
            answer = it->second;
    // 수열의 길이는 집합의 수 * 2이므로 2배 반환
    return answer * 2;
}