#include <iostream>
#include <string>

using namespace std;

bool bMinus = false;

void Solve()
{
    string str;
    cin >> str;

    int answer = 0;
    string temp = "";
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '+' || str[i] == '-') 
        {
            if(bMinus) answer -= stoi(temp);
            else answer += stoi(temp);
            temp = "";
            
            if(str[i] == '-') bMinus = true;
        }
        else temp += str[i];
    }

    cout << answer + (bMinus ? -stoi(temp) : stoi(temp));
}

int main(void)
{
    Solve();
}