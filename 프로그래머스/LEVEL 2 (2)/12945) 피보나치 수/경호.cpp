#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> result(n + 1, 0);
    result[0] = 0;
    result[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        result[i] = (result[i - 2] % 1234567) + (result[i - 1] % 1234567);
        result[i] %= 1234567;
    }
    
    return result[n];
}