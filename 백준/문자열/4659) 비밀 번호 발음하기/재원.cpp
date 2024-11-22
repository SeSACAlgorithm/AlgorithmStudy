#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkstr(string s) {
    bool has_vowel = false;
    int vowel_count = 0, consonant_count = 0;

    for (int i = 0; i < s.size(); i++) {
        bool is_vowel = (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');

        if (is_vowel) {
            has_vowel = true;
            vowel_count++;
            consonant_count = 0;
        } else {
            consonant_count++;
            vowel_count = 0;
        }

        if (vowel_count >= 3 || consonant_count >= 3) {
            return false;
        }

        if (i > 0 && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') {
            return false;
        }
    }

    if (!has_vowel) {
        return false;
    }

    return true;
}

int main() {
    string s;
    vector<string> answer;

    while (1) {
        cin >> s;

        if (s == "end")
            break;
        if (checkstr(s)) {
            s = "<" + s + "> is acceptable.";
        } else {
            s = "<" + s + "> is not acceptable.";
        }
        answer.push_back(s);
    }

    for (auto a : answer)
        cout << a << endl;

    return 0;
}
