#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> ans;
    int sum = 0;
    
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            sum = numbers[i] + numbers[j];
            ans.push_back(sum);
        }
    }
    
    // 1. 벡터 정렬
    sort(ans.begin(), ans.end());
    // 2. 중복된 쓰레기 값 맨 뒤 인덱스로 보내기
    // unique(첫 번째 인덱스부터, 마지막 인덱스까지) 중복 값을 맨 뒤로 보내고
    // 중복된 원소들을 모아둔 뒷 부분의 첫 번째 원소의 주소를 return
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    return ans;
}
