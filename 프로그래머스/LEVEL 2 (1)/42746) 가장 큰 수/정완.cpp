#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return (a + b) > (b + a);
}

string solution(vector<int> numbers)
{
    vector<string> v;
    string ans = "";
    
    for(int num : numbers)
        v.push_back(to_string(num));    // 문자열로 전환
    
    sort(v.begin(), v.end(), compare);  // 문자열 정렬
    
    for(const auto s : v)
        ans.append(s);                  // 정렬된 문자 ans에 추가
    
    if(v[0] == "0")
        return "0";                     // numbers의 인수가 0 인 경우
    
    return ans;
}
