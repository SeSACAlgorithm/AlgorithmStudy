// 문제 분석
/*
    .을 기준으로 나누기
    확장자가 몇개 있는지 이름의 사전순으로 출력
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int N; // 1 ~ 50,000
map<string, int> m_extension;

string split_str(string str)
{
    string token;
    stringstream ss(str);
    vector<string> v;
    while (getline(ss, token, '.'))
    {
        v.push_back(token);
    }

    return v[1];
}

void solve()
{
    string str;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        m_extension[split_str(str)]++;
    }

    for (auto const &pair : m_extension)
    {
        cout << pair.first << " " << pair.second << "\n";
    }
}

int main(void)
{
    solve();
}