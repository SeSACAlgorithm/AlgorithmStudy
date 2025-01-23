/*
Invalid     : 삼각형 조건 만족X
Equilateral : 세 변의 길이가 모두 같은 경우
Scalene     : 세 변의 길이가 모두 다른 경우
Isosceles   : 두 변의 길이만 같은 경우
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 마지막 줄
        if(a == 0 && b == 0 && c == 0) 
            break;

        int line[3] = {a, b, c};

        sort(line, line+3);


        // 삼각형 조건 충족X
        if(line[0] + line[1] <= line[2])
            cout << "Invalid";

        // 세 변 모두 같은 경우
        else if(line[0] == line[1] && line[1] == line[2])
            cout << "Equilateral";

        // 세 변 모두 다를 경우
        else if(line[0] != line[1] && line[1] != line[2] && line[2] != line[0])
            cout << "Scalene";

        // 두 변만 같음
        else
            cout << "Isosceles";

        cout << "\n";
    }
    
    return 0;
}