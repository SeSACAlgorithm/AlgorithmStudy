#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> arr ;
    
    arr.push_back(0);
    arr.push_back(1);
    
    for(int i = 2; i <= n + 2; i++){
        int a = arr[i-2] + arr[i-1];
        a = a % 1234567;
        arr.push_back(a);
    }
    answer = arr[n];
    return answer;
}
