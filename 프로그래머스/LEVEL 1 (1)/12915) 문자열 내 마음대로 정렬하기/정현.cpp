#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// sort(strings.begin(),strings.end(),compare) sort() 함수에서 3번째 인자를 내가 만든 함수를 넣으면
// 내 맘대로 정렬할 수 있다!!!
int a;
bool compare(string b, string c) {
    // b문자열, c문자열의 a번째 문자 비교해서 같으면 b,c 비교해서 오름차순 정렬
    if (b[a] == c[a]) {
        return b < c;
    }
    else
        // 같지 않다면 a번째 문자 기준으로 오름차순 정렬!!!
        return b[a] < c[a];
}
vector<string> solution(vector<string> strings, int n) {
    a = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}