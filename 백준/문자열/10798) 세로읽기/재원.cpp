#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    vector<string> v;       // 입력받은 문자열을 저장할 벡터
    vector<string> idxv;    // 각 인덱스별로 모은 문자열을 저장할 벡터
    string s;
    int maxsize = 0;

    // 5개의 문자열을 입력받고, 가장 긴 문자열의 길이를 maxsize에 저장
    for (int i = 0; i < 5; i++) {
        cin >> s;
        if (maxsize < s.size()) {
            maxsize = s.size();
        }
        v.push_back(s);
    }

    // maxsize 길이만큼 반복하면서 각 문자열의 해당 인덱스 값들을 모은다
    for (int i = 0; i < maxsize; i++) {
        s = "";  // 새로운 문자열을 담을 변수 초기화
        for (int j = 0; j < 5; j++) {
            // 문자열 길이가 i보다 크면 그 인덱스를 사용
            if (i < v[j].size()) {
                s += v[j][i];
            }
        }
        idxv.push_back(s);  // 모은 문자열을 idxv 벡터에 추가
    }

    // 결과 출력
    for (auto a : idxv) {
        cout << a;
    }

    return 0;
}
