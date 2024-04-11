#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long ans = 0;
    vector<int> num;
    
    while(n>0)
    {
        num.push_back(n%10);
        n /= 10;
    }
    
    sort(num.begin(), num.end(), greater<int>());
    
    for(int i =0; i<num.size(); i++)
    {
        ans = ans*10 + num[i];
    }
    
    return ans;
}
