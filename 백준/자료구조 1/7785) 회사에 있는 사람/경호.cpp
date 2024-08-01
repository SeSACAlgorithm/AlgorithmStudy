#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string enter = "enter";
    string name, action;
    map<string, bool, greater<string>> cur_left;
    for(int i = 0; i < N; ++i)
    {
        cin >> name >> action;
    	cur_left[name] = (action == enter);
    }

    for(auto it = cur_left.begin(); it != cur_left.end(); ++it)
    {
        if (it->second)
            cout << it->first << "\n";
    }
}