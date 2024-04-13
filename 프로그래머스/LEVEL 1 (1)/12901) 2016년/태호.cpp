#include <string>
#include <vector>

// 1.1 FRI
// 1.2 SAT
// 1.3 SUN
// 1.4 MON
// 1.5 TUE
// 1.6 WED
// 1.7 THU

using namespace std;

int date[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string day[7] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };

string solution(int a, int b) {

    int k = 0;

    for (int i = 0; i < a - 1; ++i)
        k += date[i];

    string answer = day[(k + b) % 7];
    return answer;
}
