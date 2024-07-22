#include <iostream>
using namespace std;

int main() {
    bool student[31] = { false };

    // 출석한 학생  true로
    for (int i = 0; i < 28; i++) {
        int n;
        cin >> n;
        student[n] = true;
    }

    // 출석하지 않은 학생 출력
    for (int i = 1; i <= 30; i++) {
        if (!student[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
