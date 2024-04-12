#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;

    stack<int> S;
    while (n)
    {
        S.push((n % 3));
        n /= 3;
    }

    int k = 0;
    while (!S.empty())
    {
        int num = S.top(); S.pop();
        answer += pow(3, k) * num; 
        ++k;
    }


    return answer;
}
