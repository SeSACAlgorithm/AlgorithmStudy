#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int ans = 0;
    
    map<char, int> alp;
    int next_word[5] = {781, 156, 31, 6, 1};     // 각 자리에서 A, E, I, O, U가 바뀔 때 건너뛰는 단어의 개수
    
    alp.insert({'A', 0});
    alp.insert({'E', 1});
    alp.insert({'I', 2});
    alp.insert({'O', 3});
    alp.insert({'U', 4});
    
    int i=0;
    for(auto w : word)
    {
        ans += 1 + alp[w] * next_word[i];       // 첫 단어는 1부터 시작함 --> "1 + " 로 시작
        i++;
    }
    return ans;
}
