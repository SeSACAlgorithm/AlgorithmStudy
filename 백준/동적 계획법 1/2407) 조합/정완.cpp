/*

       1C0 1C1
    2C0  2C1  2C2
3C0   3C1  3C2   3C3


1 1
1 2 1
1 3 3 1
1 4 6 4 1

dp[i][j] = dp[i-1][j] + dp[i-1][j-1]

*/

// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     string dp[102][102];    // 값이 커서 문자열로 처리

//     for(int i=0; i<=n; i++)
//         for(int j=0; j<=i; j++)
//         {
//             if(j == 0 || j == i)        // nC0 = nCn = 1
//                 dp[i][j] = "1";

//             else
//             {
//                 int sum = 0;
//                 string n1 = dp[i-1][j];
//                 string n2 = dp[i-1][j-1];

//                 while (!n1.empty() || !n2.empty() || sum)
//                 {
//                     if(!n1.empty())
//                     {
//                         sum += n1.back() - '0';
//                         n1.pop_back();
//                     }

//                     if(!n2.empty())
//                     {
//                         sum += n2.back() - '0';
//                         n2.pop_back();
//                     }

//                     dp[i][j].push_back((sum % 10) + '0');
//                     sum /= 10;
//                 }
                
//                 reverse(dp[i][j].begin(), dp[i][j].end());
//             }
//         }

//         cout << dp[n][m];
// }

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
string DP[102][102];

void Input()
{
    cin >> n >> m;
}

void Solution()
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == 0 || j == i)
                DP[i][j] = "1";
            
            else
            {
                int sum = 0;
                string n1 = DP[i-1][j];
                string n2 = DP[i-1][j-1];

                while(!n1.empty() || !n2.empty() || sum)
                {
                    if(!n1.empty())
                    {
                        sum += n1.back() - '0';     // string --> int
                        n1.pop_back();
                    }

                    if(!n2.empty())
                    {
                        sum += n2.back() - '0';     // string -->int
                        n2.pop_back();
                    }
                    
                    DP[i][j].push_back((sum % 10) + '0');
                    sum /= 10;
                }

                reverse(DP[i][j].begin(), DP[i][j].end());
            }
        }
    }

    cout << DP[n][m];
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    Solve();

    return 0;    
}