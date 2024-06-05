#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> vec(n+1);

    int cnt = 0;

    for(int i=2; i<=n; i++)
        vec[i] = i;

    for(int i=2; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)        // 소수의 배수 제거
        {
            if(vec[j] != 0)
            {
                vec[j] = 0;
                cnt++;

                if(cnt == k)
                    cout << j;
            }
        }
    }
}