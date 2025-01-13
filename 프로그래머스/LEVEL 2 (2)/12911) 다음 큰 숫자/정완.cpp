#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt_n = 0;              // 입력된 n의 2진수 1의 개수
    int num = n;                // n의 값 복사
    
    while(num != 0)
    {
        cnt_n += num%2;         // 나머지 남으면 1개수 증가
        num /= 2;               // 다음 비트 확인
    }
    
    for(int i=n+1; ; i++)       // 조건 1 충족하는 수 i 부터 시작
    {
        int cnt_i = 0;          // i의 2진수 1의 개수
        int div = i;            // i 값 복사
        
        while(div != 0)
        {
            cnt_i += div%2;     // 나머지 남으면 1개수 증가
            
            if(cnt_i > cnt_n)   // 조건2 충족X, 바로 다음 단계
                break;
            
            div /= 2;           // 다음 비트 확인
        }
        
        if(cnt_i == cnt_n)      // 조건 2 충족
            return i;           // 조건1, 조건2 충족하는 수 반환
    }
}
