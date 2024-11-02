#include <string>
#include <vector>

using namespace std;

string words = "AEIOU";
bool cond = false;
int answer = 0;
string k;

void dfs(string word)
{
    if (word == k)
    {
        cond = true;
        return;
    }

    if (cond || word.size() == 6)
        return;

    ++answer;

    for (int i = 0; i < words.size(); ++i)
    {
        dfs(word + words[i]);
    }
}

int solution(string word) {

    k = word;
    dfs("");
    return answer;
}
