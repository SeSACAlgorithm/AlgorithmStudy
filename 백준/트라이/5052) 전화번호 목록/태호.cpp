#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MX = 10000 * 10 + 5;
int unused = 2;
int nxt[MX][10];
bool check[MX];

int t,n;

int ctoi(char c)
{
    return c - '0';
}

bool insert(string& s)
{
    int cur = 1;

    for (char c : s)
    {
        int idx = ctoi(c);

        if (nxt[cur][idx] == -1)
            nxt[cur][idx] = unused++;

        if(check[nxt[cur][idx]])
            return false;

        cur = nxt[cur][idx];
    }
    
    if(cur != unused - 1)
        return false;

    check[cur] = true;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> t;

    while(t--)
    {
        
        fill(check, check + MX, 0);
        
        for (int i = 0; i < MX; ++i)
            fill(nxt[i], nxt[i] + 10, -1);
        
        unused = 2;
        bool valid = true;
        string str;
        
        cin >> n;
        
        while(n--)
        {
            cin >> str;
            if (!insert(str)) 
                valid = false;
        }

        if(valid) cout << "YES\n";
        else cout << "NO\n" ;
    }


    return 0;

}
