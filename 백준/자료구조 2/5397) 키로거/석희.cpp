#include <iostream>
#include <list>

using namespace std;

int t;  // 테스트 케이스 개수

void Solve(string command)
{
    list<char> password;
    list<char>::iterator it = password.begin();

    for(int i = 0; i < command.length(); i++)
    {
        if(command[i] == '<')
        {
            if(it != password.begin()) it--;
        }
        else if(command[i] == '>')
        {
            if(it != password.end()) it++;
        }
        else if(command[i] == '-')
        {
            if(it != password.begin()) 
            {
                it--;
                it = password.erase(it);
            }
        }
        else
        {
            password.insert(it, command[i]);
        }
    }

    for(auto p : password) cout << p;
    cout << "\n";
}

int main(void)
{
    cin >> t;

    string str;
    for(int i = 0; i < t; i++)
    {
        cin >> str;
        Solve(str);
    }
}