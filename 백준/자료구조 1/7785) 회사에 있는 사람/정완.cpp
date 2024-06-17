#include "iostream"
#include "set"

using namespace std;

int main()
{
    string name = "";
    string IO = "";

    set<string> record;

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> name;
        cin >> IO;

        if( IO == "enter")
            record.insert(name);

        else
            record.erase(name);
    }

    for(auto it = record.rbegin(); it != record.rend(); it++)   // 역순 출력
        cout << *it << '\n';
}