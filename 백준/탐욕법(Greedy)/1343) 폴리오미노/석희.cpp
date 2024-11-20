#include <iostream>
#include <vector>

using namespace std;

string str;
string answer;

string p1 = "AAAA";
string p2 = "BB";

void Input()
{
    cin >> str;
}

void Solve()
{
    vector<int> v;
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'X') count++;
        else
        {
            if(count % 2 != 0) break;

            answer += '.';
            count = 0;
        }

        if(count == 2 && str[i+1] != 'X')
        {
            answer += p2;
            count = 0;
        }
        if(count == 4)
        {
            answer += p1;
            count = 0;
        }
    }

    if(count % 2 != 0) cout << "-1";
    else cout << answer;
}

int main(void)
{
    Input();
    Solve();
}