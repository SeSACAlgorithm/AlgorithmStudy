#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int pointer = 0;
vector<int> arr;
vector<int> answer;

void fillVector()
{
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
}

void process()
{
    while(!arr.empty())
    {
        pointer = (pointer + k-1) % arr.size();
        answer.push_back(arr[pointer]);
        arr.erase(arr.begin() + pointer);
    }
}

void printAnswer()
{
    cout << "<";

    for(int i = 0; i < answer.size()-1; i++)
    {
        cout << answer[i] << ", ";
    }
    cout << answer.back() << ">";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;
    
    fillVector();
    process();
    printAnswer();

    return 0;
}
