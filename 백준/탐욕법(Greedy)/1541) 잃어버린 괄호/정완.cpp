#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    bool chk = false;           // 기호 - 판별
    string num = "";            // 식에 사용될 숫자
    int min_ans = 0;            // 최솟값

    for(int i=0; i<=str.size(); i++)
    {
        // case 1 -> 기호 or 문자열의 끝
        if(str[i] == '-' || str[i] == '+' || i == str.size())
        {
            // 기호가 - 일 경우, + 일 경우
            min_ans += (chk ? -stoi(num) : +stoi(num));

            num = "";   // 값을 더해주고 초기화

            if(str[i] == '-') chk = true;
        }

        // case 2 -> 숫자
        else num += str[i];
    }

    cout << min_ans;

    return 0;
}