#include <iostream>
#include <string>

using namespace std;

string str;
int len, cnt = 0;

int recursion(int l, int r)
{
    cnt = cnt + 1;


    if (l >= r) return 1;                           // 모든 범위를 탐색했다면
    else if (str[l] != str[r]) return 0;            // 팰린드롬이 아닌 경우
    else return recursion(l + 1, r - 1);
}

int isPalindrome()
{
    return recursion(0, len - 1);
}

int main()
{
    int T;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> str;
        len = str.length();
        cnt = 0;

        cout << isPalindrome() << " " << cnt << "\n";
    }
}