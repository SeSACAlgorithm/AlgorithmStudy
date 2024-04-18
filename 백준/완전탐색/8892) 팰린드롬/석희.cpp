#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T;
string answer = "";

string solve(int k, vector<string> v_str);
bool find_palindrome(string str);

void input()
{
    int k = 0;
    string str1 = "";

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        vector<string> v_str;

        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> str1;
            v_str.push_back(str1);
        }

        cout << solve(k, v_str) << "\n";
    }
}

// 입력받은 문자열들 계속 더하면서 팰린드롬 찾기
// -> 찾으면 바로 그 값 return
// -> 끝까지 돌았는데도 return이 안된 경우는 없는 경우이므로 0 리턴
string solve(int k, vector<string> v_str)
{
    string str = "";
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == j) continue;
            str = v_str[i] + v_str[j];
            if (find_palindrome(str)) return str;
        }
    }

    return "0";
}

// 문자열이 팰린드롬인지 확인
bool find_palindrome(string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - i - 1]) return false;
    }

    return true;
}

int main(void)
{
    input();
}