#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
    if(n<=1) return false;                      // 0, 1은 소수 X
    
    for(int i=2; i<=sqrt(n); i++)
        if(n % i == 0) return false;            // 나누어 떨어지면 소수 X
    
    return true;                                // 약수 없으면 소수 O
}

int solution(string numbers)
{
    int ans = 0;
    set<int> s;                                 // 중복 제거를 위한 set
    
    sort(numbers.begin(), numbers.end());       // 입력된 문자열 정렬
    
    do
    {
        for(int i=1; i<=numbers.size(); i++)
        {
            string ss = numbers.substr(0, i);   // 길이가 i인 부분 문자열 추출
            int num = stoi(ss);                 // 문자열 -> 정수형
            
            if(isPrime(num))                    // 소수 판별
                s.insert(num);
        }
    }
    
    while (next_permutation(numbers.begin(), numbers.end()));
    
    ans = s.size();                             // set 으로 중복 제거된 소수의 계수 반환
    
    return ans;
}
