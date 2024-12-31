#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> answer;
    int x, y, z;

    while (true) {
        cin >> x >> y >> z;

        if (x == 0 && y == 0 && z == 0)
            break;

        // 삼각형 유효성 검사
        if (x + y <= z || x + z <= y || y + z <= x) {
            answer.push_back("Invalid");
        } else if (x == y && y == z) {
            answer.push_back("Equilateral");
        } else if (x == y || y == z || x == z) {
            answer.push_back("Isosceles");
        } else {
            answer.push_back("Scalene");
        }
    }

    // 결과 출력
    for (const string& res : answer) {
        cout << res << endl;
    }

    return 0;
}
