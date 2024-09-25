#include <string>

using namespace std;

enum Number { Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, unknown };

// 문자열을 열거형 값으로 변환하는 함수
Number convertstrtonum(string target) {
    if (target == "zero") return Zero;
    else if (target == "one") return One;
    else if (target == "two") return Two;
    else if (target == "three") return Three;
    else if (target == "four") return Four;
    else if (target == "five") return Five;
    else if (target == "six") return Six;
    else if (target == "seven") return Seven;
    else if (target == "eight") return Eight;
    else if (target == "nine") return Nine;
    else return unknown;
}

// 주어진 문자열을 숫자로 변환하는 함수
int solution(string s) {
    int answer = 0;
    string temp = "";
    string number = "";
    Number num;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {  // 숫자인 경우 그대로 추가
            number += s[i];
        } else {  // 숫자가 아닌 경우 문자열을 조합하여 숫자 변환
            temp += s[i];
            num = convertstrtonum(temp);  // 단어가 숫자에 해당하는지 확인

            switch (num) {
                case Zero:
                    number += "0";
                    temp = "";
                    break;
                case One:
                    number += "1";
                    temp = "";
                    break;
                case Two:
                    number += "2";
                    temp = "";
                    break;
                case Three:
                    number += "3";
                    temp = "";
                    break;
                case Four:
                    number += "4";
                    temp = "";
                    break;
                case Five:
                    number += "5";
                    temp = "";
                    break;
                case Six:
                    number += "6";
                    temp = "";
                    break;
                case Seven:
                    number += "7";
                    temp = "";
                    break;
                case Eight:
                    number += "8";
                    temp = "";
                    break;
                case Nine:
                    number += "9";
                    temp = "";
                    break;
                case unknown:
                    // 알 수 없는 값은 무시
                    break;
            }
        }
    }

    // number에 저장된 숫자 문자열을 정수로 변환하여 answer에 저장
    answer = stoi(number);
    return answer;
}
