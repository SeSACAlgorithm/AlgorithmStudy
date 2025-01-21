#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)   // 최대 공약수
{
    return b ? gcd(b, a%b) : a;
}

int lcd(int a, int b)   // 최소 공배수
{
    return a * (b / gcd(a, b));
}

int solution(vector<int> arr)
{
    int ans = arr[0];
    
    for(int i=1; i<arr.size(); i++)
        ans = lcd(ans, arr[i]);
    
    return ans;
}
