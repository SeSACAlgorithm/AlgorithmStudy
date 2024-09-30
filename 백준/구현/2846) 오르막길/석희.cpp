#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Pi[1001];
vector<int> temp;

int calc_temp()
{
    sort(temp.begin(), temp.end(), greater<int>());
    return (temp.front() - temp.back());
}

int main(void)
{
    int max_uphill = 0;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> Pi[i];
    }

    for(int i = 0; i < N; i++)
    {
        temp.push_back(Pi[i]);

        if(i != N-1 && Pi[i] >= Pi[i+1]) 
        {
            max_uphill = max(calc_temp(), max_uphill);
            if(!temp.empty()) temp.clear();
        }
    }

    if(!temp.empty())
    {
        max_uphill = max(calc_temp(), max_uphill);
    }

    cout << max_uphill;
}