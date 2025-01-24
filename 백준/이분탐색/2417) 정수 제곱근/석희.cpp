// 2^63 - 1 = unsigned long long
#define ULL unsigned long long

#include <iostream>
#include <cmath>

using namespace std;

ULL n;

ULL binary_search()
{
    ULL left = 1;
    ULL right = n + 1;
    ULL answer = n;
    
    while(left <= right)
    {
        ULL mid = (left + right) / 2;

        if(pow(mid, 2) >= n)
        {
            right = mid - 1;
            answer = min(answer, mid);
        }
        else left = mid + 1;
    }

    return answer;
}


int main(void)
{
    cin >> n;
    cout << binary_search();
}
