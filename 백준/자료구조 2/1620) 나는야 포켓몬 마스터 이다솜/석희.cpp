#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M;
map<string, int> mCollectionString;
map<int, string> mCollectionInt;

void solve()
{
    string question = "";

    for (int i = 0; i < M; i++)
    {
        cin >> question;
        if (isdigit(question[0]))
            cout << mCollectionInt[stoi(question)] << "\n";
        else
            cout << mCollectionString[question] << "\n";
    }
}

void input()
{
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        mCollectionString.insert({ name, i + 1 });
        mCollectionInt.insert({ i + 1, name });
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    input();
    solve();
}