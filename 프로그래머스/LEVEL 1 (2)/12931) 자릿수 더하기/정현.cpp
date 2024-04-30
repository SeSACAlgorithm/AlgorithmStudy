#include <iostream>
#include <string>

using namespace std;

// 이건 내가 함
//int solution(int n)
//{
//    int answer = 0;
//
//    while (n != 0) // n 이 0이 아닐 때까지 반복해서 계속 일의 자리수 더하자
//    {
		 // 자리수 별로 하나씩 answer에 더하기
         // 일의 자리수 하나씩 더하자
//        answer += n % 10; // 일의 자리 더하고
//        n /= 10; // 더해준 일의 자리 버려
//    }
//    return answer;
//}

// 윤지 언니꺼 봄
int solution(int n)
{
	int ans = 0;

	string str = to_string(n); // 자리수 별 계산하기 위해 string으로 변환

	for (int i = 0; i < str.size(); i++)
	{
		ans += str[i] -'0'; // 문자로 바꿔잖아 아스키코드 48 빼주면 해당 문자가 이제 숫자가 되는거야!!!! 이거야!!!!
	}
	return ans;
}