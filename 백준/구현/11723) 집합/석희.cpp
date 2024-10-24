#include <iostream>
#include <cstring>

using namespace std;

int S[21];

void MakeS()
{
    for(int i = 1; i <= 20; i++)
    {
        S[i] = 1;
    }
}

void Solve(string str)
{
    int x;
    if(str == "add")
    {
        cin >> x;
        S[x] = 1;
    }
    else if(str == "remove")
    {
        cin >> x;
        S[x] = 0;
    }
    else if(str == "check")
    {
        cin >> x;
        if(S[x] == 1) cout << "1" << "\n";
        else cout << "0" << "\n";
    }
    else if(str == "toggle")
    {
        cin >> x;
        if(S[x] == 1) S[x] = 0;
        else S[x] = 1;
    }
    else if(str == "all")
    {
        MakeS();
    }
    else if(str == "empty")
    {
        memset(S, 0, sizeof(S));
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int M;
    string command;

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> command;
        Solve(command);
    }
}