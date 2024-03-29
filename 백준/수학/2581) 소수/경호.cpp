#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int min = 0, max = 0;
    cin >> min >> max;

    vector<int> answer;

    for(int i = min; i <= max; i++)
    {
        if(i < 2) continue;
        
        int limit = sqrt(i);
        bool isPrime = true;
        for(int j = 2; j <= limit; j++)
        {
	        if(i % j == 0)
	        {
                isPrime = false;
                break;
	        }
        }
        if (isPrime) 
            answer.push_back(i);
    }

    if (answer.empty())
        cout << -1 << '\n';
    else
        cout << accumulate(answer.begin(), answer.end(), 0) << '\n' << answer[0] << '\n';
}