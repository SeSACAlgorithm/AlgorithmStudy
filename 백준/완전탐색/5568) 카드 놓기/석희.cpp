#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
string cards[10];
set<string> nums;

vector<string> temp;
bool visit[11];

void Input()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }
}

void MakeNums(int index)
{
    if(index == k)
    {
        string str = "";
        for(int i = 0; i < temp.size(); i++)
        {
            str += temp[i];
        }

        nums.insert(str);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visit[i]) continue;

        temp.push_back(cards[i]);
        visit[i] = true;

        MakeNums(index + 1);

        temp.pop_back();
        visit[i] = false;
    }
}

int main(void)
{
    Input();
    MakeNums(0);
    cout << nums.size();
}