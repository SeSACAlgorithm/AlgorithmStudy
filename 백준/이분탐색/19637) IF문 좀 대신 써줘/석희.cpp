#include <iostream>

using namespace std;

int N, M;
string titles[1000000];
int powers[1000000];

void binary_search(int power)
{
    int left = 0;
    int right = N - 1;
    int mid = 0;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(power <= powers[mid])
            right = mid - 1;
        else left = mid + 1;
    }

    if (power > powers[mid]) cout << titles[mid + 1] << '\n';
    else cout << titles[mid] << "\n";
}

void Solve()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> titles[i] >> powers[i];
    }

    int power;
    for(int i = 0; i < M; i++)
    {
        cin >> power;
        binary_search(power);
    }
}

int main(void)
{
    Solve();
}