#include <iostream>
#include <string>
using namespace std;

int main() {
    int N; 
    cin >> N;

    int group = 0; 

    // 각 단어를 처리
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        bool isGroupWord = true; // 현재 단어가 그룹 단어인지 체크
        bool alphabet[26] = { false };

        // 단어의 각 문자를 체크
        for (int j = 0; j < word.length(); j++) {
            int current = word[j] - 'a'; 
            
            // 현재 문자가 이전 문자와 같지 않고, 이미 출현한 문자라면 그룹 단어가 아님
            if (j > 0 && word[j] != word[j - 1] && alphabet[current]) {
                isGroupWord = false;
                break;
            }
            
            alphabet[current] = true;
        }

        // 그룹 단어일 경우 카운트 증가
        if (isGroupWord) {
            group++;
        }
    }

    cout << group << endl;

    return 0;
}
