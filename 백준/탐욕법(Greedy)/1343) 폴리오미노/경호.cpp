#include <iostream>
#include <string>

using namespace std;

#define POLY_A "AAAA"
#define POLY_B "BB"

bool translate_polyomino(string& input, int& left, int& right)
{
    // 길이가 홀수라면 변환이 불가능하므로 false
    int count = right - left + 1;
    if ((count & 1) == 1)
        return false;

    // 길이가 4 이상이라면 우선적으로 AAAA로 변환
    while (right - left + 1 >= 4)
    {
        input.replace(input.begin() + left, input.begin() + left + 4, POLY_A);
        left += 4;
    }
    // 남은 길이는 BB로 변환
    while (right - left > 0)
    {
        input.replace(input.begin() + left, input.begin() + left + 2, POLY_B);
        left += 2;
    }

    // left 초기화 및 true 반환
    left = -1;
    return true;
}

int main()
{
    string input;
    cin >> input;

    int left = -1, right = 0;
    for(int i = 0; i < input.size(); ++i)
    {
        // X가 나왔고 left가 초기값이라면 갱신
        // right 갱신
	    if(input[i] == 'X')
	    {
		    if(left == -1)
                left = i;
            right = i;
            continue;
	    }
        // .이 나왔으나 변환해야 할 X가 없다면 패스
        if (left == -1)
            continue;

        // 변환 체크 및 불가능하다면 -1 출력 후 종료
        if (false == translate_polyomino(input, left, right))
        {
            cout << -1;
            return 0;
        }
    }
    // X가 아직 남아있다면 한번 더 변환
    if(left != -1)
    {
        if(false == translate_polyomino(input, left, right))
        {
            cout << -1;
            return 0;
        }
    }

    cout << input;
}