#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
vector<int> answer(2, 0);

int zero = 0, round = 0; //횟수와 , 없엔 0의 개수가 들어갈 공간

while(s != "1")//문제의 조건처럼 s가 1이 될때까지 반복한다
{
    string tmp = ""; // 계산할때 사용하기위해 string 생성 
    int num;
    round++; // 이진 변환 횟수 증가

    for(int i = 0; i < s.size(); i++) //문자열s 처음부터 끝까지 검사
    {
        if(s[i] == '0') // 0이면 0개수 증가
            zero++;
        else // 1이면 tmp에 문자열 "1"을 붙인다(append)
            tmp += "1";
    }

    num = tmp.size();// 0을 제거하여 만들어진 문자열 tmp의 크기를 num 변수에 넣는다
    s = ""; //이진변환 후 문자열에 새로 채우기위해 문자열 s 초기화 
    while(num > 0) //이진변환함수 빡치네 이렇게쉽게한다고 
    {
        s += to_string(num % 2); //to_string(int)= 숫자 -> 스트링형 변환 함수 
        num /= 2;
    }
}

answer[0] = round;
answer[1] = zero;
return answer;
}
