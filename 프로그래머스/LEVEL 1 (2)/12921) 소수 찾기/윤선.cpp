#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <bool> v(n+1, true);
    for (int i = 2; i <= n; i++){
        if (v[i] == true){
            // i의 배수 찾기
            for (int j = 2; j*i <= n; j++){
                // i의 배수인 경우는 false
                v[j*i] = false;
            }
            answer++;
        }
    }
    return answer;
}
