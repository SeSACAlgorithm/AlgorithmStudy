// 문제 분석
/*
    종류별로 최대 한가지 의상만 착용
    조합이 다르면 다른 방법
    최소 한개 의상은 입어야 함

    서로 다른 옷의 조합의 수는?

    -> 각 의상의 종류 + 그 의상은 안입는 경우 => (temp.second + 1)
    -> 모두 안입는 경우는 빼야하니까 => (answer - 1)
    입력 : clothes (의상의 이름, 의상의 종류)
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m_cloth;
    for(int i = 0; i < clothes.size(); i++)
    {
        m_cloth[clothes[i][1]]++;
    }

    for(auto temp : m_cloth)
    {
        answer = answer * (temp.second + 1);
    }

    return answer - 1;
}