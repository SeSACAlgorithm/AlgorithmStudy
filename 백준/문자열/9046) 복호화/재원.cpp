#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

char calmanyword(string s)
{
    map<char, int> m;
    int max = 0;
    char maxc = s[0];
    bool tie = false;  // 빈도가 같은 문자가 있는지 여부를 추적하는 변수

    // 공백을 제외한 각 문자들의 빈도 세기
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')  // 공백 제외
        {
            m[s[i]]++; // 해당 문자 빈도 증가
        }
    }

    // 가장 많이 나온 문자를 찾기
    for (auto a : m)
    {
        if (a.second > max)
        {
            max = a.second;
            maxc = a.first;
            tie = false;  // 새로운 최대값이 발견되면 tie를 false로 설정
        }
        else if (a.second == max)
        {
            tie = true;  // 빈도가 같은 문자가 있으므로 tie를 true로 설정
        }
    }

    // 빈도가 같은 문자가 있으면 '?' 출력, 아니면 가장 많이 나온 문자 출력
    if (tie)
    {
        return '?';
    }
    else
    {
        return maxc;
    }
}

int main()
{
    string s;
    vector<char> v;
    int count;

    cin >> count;
    cin.ignore();  // count 이후 남은 개행 문자 처리

    // 주어진 개수만큼 문자열 입력받고 결과 벡터에 저장
    for (int i = 0; i < count; i++)
    {
        getline(cin, s);
        v.push_back(calmanyword(s));
    }

    // 결과 출력
    for (auto a : v)
    {
        cout << a << endl;
    }

    return 0;
}
