#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double ans = 0;
    int A;
    for(int i=0; i<arr.size(); i++)
    {
        ans += arr[i];
    }
    return ans/arr.size();
}