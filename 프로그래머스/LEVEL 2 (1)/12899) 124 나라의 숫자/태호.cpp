#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string arr = "412";

string solution(int n) {
    string answer = "";

    while (n)
    {
        int remainder = n % 3;

        answer += arr[remainder];

        n /= 3;

        if (!remainder)
            --n;
    }

    reverse(answer.begin(), answer.end());

    return answer;
}
