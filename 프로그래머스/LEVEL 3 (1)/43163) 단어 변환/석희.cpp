#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 서로 바꿀수있는 관계인지 확인
bool check_same_word(string words1, string words2)
{
    int same = 0;
    for (int k = 0; k < words1.length(); k++)
        if (words1[k] == words2[k])
            same++;

    return same == words1.length()-1 ? true : false;
}

// 몇개를 거쳐야 변환 가능한지 확인
int bfs(string begin, string target, vector<string> words)
{
    int check[51] = {0, };

    // 문자열, 거친 단계 수
    queue<pair<string, int>> q_word;

    q_word.push({begin, 0});
    while (!q_word.empty())
    {
        string word = q_word.front().first;
        int count = q_word.front().second;
        q_word.pop();

        if(word == target) return count;

        for (int i = 0; i < words.size(); i++)
        {
            if (check[i] != 0) continue;
            if(!check_same_word(words[i], word)) continue;

            check[i]++;
            q_word.push({words[i], count + 1});
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    // target이 words에 없어서 변환할 수 없는 경우엔 0 리턴
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    return bfs(begin, target, words);
}