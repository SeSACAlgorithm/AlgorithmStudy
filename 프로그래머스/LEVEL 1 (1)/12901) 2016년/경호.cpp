#include <string>
#include <vector>
#include <numeric>

using namespace std;

string solution(int a, int b) {
    vector<string> what{ "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    vector<int> days{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int count = accumulate(days.begin(), days.begin() + a - 1, 0) + b;
    return what[count % 7];
}
