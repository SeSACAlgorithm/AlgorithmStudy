#include <iostream>
#include <string>
#include <cctype> // for isdigit function
#include <vector>

using namespace std;

int calculateScore(int base, char bonus) {
    if (bonus == 'S') return base;
    if (bonus == 'D') return base * base;
    if (bonus == 'T') return base * base * base;
    return 0; // Should never reach here
}

int solution(string dartResult) {
    vector<int> scores;
    int currentScore = 0;
    
    for (int i = 0; i < dartResult.size(); ++i) {
        char c = dartResult[i];
        
        if (isdigit(c)) {
            // Handle multi-digit numbers
            int j = i;
            while (j < dartResult.size() && isdigit(dartResult[j])) {
                currentScore = currentScore * 10 + (dartResult[j] - '0');
                j++;
            }
            i = j - 1; // Move the index to the last processed digit
        } else if (c == 'S' || c == 'D' || c == 'T') {
            currentScore = calculateScore(currentScore, c);
            scores.push_back(currentScore);
            currentScore = 0; // Reset currentScore after processing
        } else if (c == '*') {
            if (!scores.empty()) {
                scores.back() *= 2;
            }
            if (scores.size() > 1) {
                scores[scores.size() - 2] *= 2;
            }
        } else if (c == '#') {
            if (!scores.empty()) {
                scores.back() *= -1;
            }
        }
    }
    
    int answer = 0;
    for (int score : scores) {
        answer += score;
    }
    
    return answer;
}
