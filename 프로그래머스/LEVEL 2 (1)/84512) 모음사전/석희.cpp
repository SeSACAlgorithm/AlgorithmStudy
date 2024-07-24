#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;

    int index[5] = {1, 6, 31, 156, 781};
    map<char, int> m_dic= {{'A', 0}, {'E', 1},{'I', 2}, {'O', 3}, {'U', 4}};

    for(int i = 0; i < word.size(); i++)
    {
        answer +=  1 + (m_dic[word[i]] * index[4-i]);
    }

    return answer;
}

int main(void)
{

}