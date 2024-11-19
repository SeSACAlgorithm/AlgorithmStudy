#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vPrices;

void Input()
{
    cin >> N;

    int price;
    for(int i = 0; i < N; i++)
    {
        cin >> price;
        vPrices.push_back(price);
    }
}

void Solve()
{
    int answer = 0;

    sort(vPrices.begin(), vPrices.end(), greater<int>());
    for(int i = 0; i < N; i++)
    {
        if(i % 3 != 2) answer += vPrices[i];
    }
    cout << answer;
}

int main(void)
{
    Input();
    Solve();
}