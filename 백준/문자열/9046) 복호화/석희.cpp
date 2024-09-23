// 문제 분석
/*
    가장 많이 등장하는 문자 찾기 (만약 여러개라면 "?" 출력)

    1. 맵 사용 (알파벳 당 개수를 확인해야 하기 때문. 그리고 정렬도 필요함)
    2. value를 기준으로 정렬 (vector에 옮겨서 sort 사용.)
    만약 1등의 value와 2등의 value가 같다면 "?" 출력 아니라면 1등 Key 출력
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<char, int> &a, pair<char, int> &b)
{
    if(a.first == b.first) return a.first > b.first;
    return a.second > b.second;
}

void solve(string str)
{
    map<char, int> alphabet;
    
    for(char c : str)
    {
        if(c == ' ') continue;
        alphabet[c]++;
    }

    // value를 기준으로 정렬
    vector<pair<char, int>> v_alphabet(alphabet.begin(), alphabet.end());
    sort(v_alphabet.begin(), v_alphabet.end(), comp);

    // 제일 큰 값이 두개 이상인지 확인
    int max = v_alphabet[0].second;
    if (v_alphabet.size() > 1)
    {
        if (max == v_alphabet[1].second) max = -1;
    }

    max == -1 ? cout << "?" : cout << v_alphabet[0].first;
    cout << "\n";
}

int main(void)
{
    int T;
    cin >> T;
    cin.ignore();       // 버퍼에 남아 있는 엔터 없애기

    for (int i = 0; i < T; i++)
    {
        string str;
        getline(cin, str);

        solve(str);
    }
}