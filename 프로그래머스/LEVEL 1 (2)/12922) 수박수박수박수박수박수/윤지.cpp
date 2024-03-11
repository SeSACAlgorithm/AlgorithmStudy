#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    string a = "¼ö";
    string b = "¹Ú";

    for (int i = 1; i <= n; i++) {
        if (i % 2) answer += a;
        else answer += b;
    }

    return answer;
}