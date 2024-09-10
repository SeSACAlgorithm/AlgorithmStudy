#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    while (true) {
        // 세 변의 길이를 저장할 배열
        int side[3];
        
        cin >> side[0] >> side[1] >> side[2];

        if (side[0] == 0 && side[1] == 0 && side[2] == 0) {
            break;
        }

        // 가장 긴 변이 맨 마지막에 오게
        sort(side, side + 3);

        // 가장 긴 변이 다른 두 변의 합보다 크거나 같으면 Invalid
        if (side[2] >= side[0] + side[1]) {
            cout << "Invalid\n";
        }
        // 세 변의 길이가 모두 같으면 Equilateral
        else if (side[0] == side[1] && side[1] == side[2]) {
            cout << "Equilateral\n";
        }
        // 두 변의 길이가 같으면 Isosceles
        else if (side[0] == side[1] || side[1] == side[2]) {
            cout << "Isosceles\n";
        }
        // 세 변의 길이가 모두 다르면 Scalene
        else {
            cout << "Scalene\n";
        }
    }

    return 0;
}
