#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> used_Word;
    
    used_Word.insert(words[0]);
    
    for(int i=1; i<words.size(); i++)
    {
        // 1. 중복된 단어 체크
        // 2. 현재 단어의 첫글자 그 전 단어의 마지막 글자 비교
        if(used_Word.find(words[i]) != used_Word.end() || words[i].front() != words[i-1].back())  
            return {(i % n) + 1, (i / n) +1};
        
        // 새로운 단어 입력
        used_Word.insert(words[i]);
    }
    
    return {0, 0};
}
