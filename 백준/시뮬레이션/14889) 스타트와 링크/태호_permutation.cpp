#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result = 0x7f7f7f7f;

int board[21][21];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    vector<int> permutation(n);

    for(int i = 0; i < n / 2; ++i)
        permutation[i] = 1;

    for (int i = n / 2; i < n; ++i)
        permutation[i] = 2;

    do
    {
        vector<int> team1;
        vector<int> team2;

        for (int i = 0; i < permutation.size(); ++i)
        {
            if(permutation[i] == 1)
                team1.push_back(i);

            else if (permutation[i] == 2)
                team2.push_back(i);
        }

        int num1 = 0;
        int num2 = 0;

        for (int i = 0; i < team1.size(); ++i)
        {
            for (int j = 0; j < team1.size(); ++j)
            {
                if(i == j) continue;
                num1 += board[team1[i]][team1[j]];
                num2 += board[team2[i]][team2[j]];
            }
        }

        result = min(result, abs(num1 - num2));

    } while(next_permutation(permutation.begin(), permutation.end()));
    

    cout << result;
}
