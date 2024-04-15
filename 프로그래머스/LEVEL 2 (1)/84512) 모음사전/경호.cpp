#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> offsets{ 781, 156, 31, 6, 1 };
    map<char, int> alphabets{{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};
    
    for(int i = 0; i < word.size(); ++i)
    {
        ++answer;
        answer += alphabets[word[i]] * offsets[i];
    }
    
    return answer;
}