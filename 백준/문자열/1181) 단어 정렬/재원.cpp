#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool compare(const string& a, const string& b) {
    // 길이가 같으면 사전 순으로, 다르면 길이 순으로 정렬
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;

    set<string> words;  // 중복을 없애기 위해 set 사용

    // 단어 입력 받기
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        words.insert(word);  // set은 자동으로 중복 제거
    }

    // set을 vector로 변환하여 정렬 (길이 순, 사전 순으로 정렬)
    vector<string> sorted_words(words.begin(), words.end());
    
    sort(sorted_words.begin(), sorted_words.end(), compare);

    // 출력
    for (const string& word : sorted_words) {
        cout << word << endl;
    }

    return 0;
}
