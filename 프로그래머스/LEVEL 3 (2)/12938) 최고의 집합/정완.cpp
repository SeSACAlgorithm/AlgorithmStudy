#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> ans;
    if(n>s)
        return {-1};
    
    while(n != 0)
    {
        int a = s / n;
        ans.push_back(a);
        s -= a;
        n--;
    }
    
    return ans;
}
