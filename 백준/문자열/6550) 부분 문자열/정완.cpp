// KMP 알고리즘 참고 사이트
// https://sfer7.tistory.com/11

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> fail(string pt)
{
    vector<int> table(pt.size(), 0);    // 실패 함수를 담을 vector 초기화
    int j=0;                            // 패턴 문자열 순회 포인터

    for(int i=1; i<pt.size(); i++)
    {
        /* 0번 인덱스에는 접두사(시작) 접미사(끝)가
        공존할 수 없으므로 0 이상부터 반복문 */
        while (j>0 && pt[i] != pt[j])   // 패턴 내에서 일치하지 않는 부분을 찾을 때 까지 이전 위치로 이동
            j = table[--j];

        if(pt[i] == pt[j])              // 일치하는 값이 있을 시 실패함수 값 갱신          
            table[i] = ++j;
    }

    return table;
}

// KMP 알고리즘 함수
bool KMP(string s, string pt, vector<int>& table)
{
    int j=0;

    for(int i=0; i<s.size(); i++)
    {
        while (j>0 && s[i] != pt[j])    // 일치하지 않는 부분을 찾을 때 까지 j값 갱신
            j = table[--j];

        if(s[i] == pt[j])               // 패턴 문자열이 일치한 경우
        {
            if(j == pt.size() - 1)      // 패턴의 끝까지 일치한 경우 true 반환
                return true;

            else                        // 패턴의 끝까지 일치하지 않은 경우 j값 증가
                j++;
        }
    }

    return false;       // 아예 일치한 게 없는 경우 false 반환
}

int main()
{
    string s, pt;
    cin >> s >> pt;

    vector<int> table = fail(pt);
    cout << KMP(s, pt, table);
}
