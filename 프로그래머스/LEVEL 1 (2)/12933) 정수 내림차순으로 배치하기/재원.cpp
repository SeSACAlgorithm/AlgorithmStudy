#include <string>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    // 정수를 문자열로 변환
    string temp = to_string(n);
    
    // 문자열의 각 자릿수를 내림차순으로 정렬
    sort(temp.begin(), temp.end(), greater<char>());
    
    // 정렬된 문자열을 long long으로 변환
    answer = stoll(temp);
    
    return answer;
}
