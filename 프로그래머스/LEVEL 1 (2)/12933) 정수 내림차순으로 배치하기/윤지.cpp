#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string a = to_string(n);
    sort(a.begin(),a.end(),greater<>());
    answer = stol(a);
    
    return answer;
}
