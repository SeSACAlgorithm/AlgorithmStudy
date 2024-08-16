// 문제 분석
/*
    1. 모음 하나를 반드시 포함 (a, e, i, o, u)
    2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안됨
    3. 같은 글자 연속 X (ee, oo 는 허용)
    4. 대문자는 없음 (1이상 20이하의 문자열)

    end가 나오면 멈추기
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> m_vowel;

bool check_str(string str)
{
    // 모음 하나 반드시 포함
    bool check_vowel = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (m_vowel[str[i]])
            check_vowel = true;
    }
    if (check_vowel == false)
        return false;

    // 자음이나 모음 연속 3개
    int vowel_num = 0;
    int cons_num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (m_vowel[str[i]])
        {
            vowel_num++;
            cons_num = 0;
        }
        else
        {
            vowel_num = 0;
            cons_num++;
        }

        if (cons_num == 3 || vowel_num == 3)
            return false;
    }

    // 같은 글자 2개 연속
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] != 'e' && str[i] != 'o')
        {
            if (str[i] == str[i - 1])
                return false;
        }
    }

    return true;
}

int main(void)
{
    string str;

    m_vowel.insert({'a', 1});
    m_vowel.insert({'e', 1});
    m_vowel.insert({'i', 1});
    m_vowel.insert({'o', 1});
    m_vowel.insert({'u', 1});

    while (1)
    {
        cin >> str;

        if (str == "end")
            return 0;

        bool flag = false;
        flag = check_str(str);

        cout << "<" << str << "> is ";
        cout << (flag ? "acceptable." : "not acceptable.") << "\n";
    }
}