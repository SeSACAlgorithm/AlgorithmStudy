#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성
// 정렬된 문자임 ex) abc (o) bac(x)
// 서로 다은 알파벳 소문자 n 문자의 종류 m

int n, m;
char values[20];
char arr[20];
bool visited[20];
string mo = "aeiou";

bool Check(char c)
{
    for (int i = 0; i < mo.size(); ++i)
    {
        if(c == mo[i])
            return true;
    }

    return false;
}

void Solve(int cur)
{
    if (cur == n)
    {
        int moja[2] = {0, 0};

        for (int i = 0; i < n; ++i)
            Check(arr[i]) ? ++moja[0] : ++moja[1];

        if (moja[0] >= 1 && moja[1] >= 2)
        {
            for (int i = 0; i < n; ++i)
                cout << arr[i];

            cout << '\n';
        }

        return;
    }

    for (int i = 1; i <= m; ++i)
    {
        if(visited[i]) continue;
        if (cur != 0)
        {
            if (arr[cur - 1] > values[i]) continue;
        }

        visited[i] = true;
        arr[cur] = values[i];
        Solve(cur + 1);
        visited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
        cin >> values[i];
    
    sort(values + 1, values + m + 1);
    Solve(0);

    return 0;
}
