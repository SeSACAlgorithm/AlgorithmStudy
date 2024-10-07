#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    vector<int> v;
    stringstream ss(s);
    string temp;

    // 문자열을 공백 기준으로 나누어 처리
    while (ss >> temp) {
        v.push_back(stoi(temp)); // 숫자를 벡터에 추가
    }

    // 벡터 정렬
    sort(v.begin(), v.end());

    // 가장 작은 값과 가장 큰 값을 답으로 만듦
    string answer = to_string(v[0]) + " " + to_string(v[v.size() - 1]);

    return answer;
}
