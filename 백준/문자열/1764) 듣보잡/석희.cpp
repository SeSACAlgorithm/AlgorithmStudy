// 문제 분석
/*
    
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> person;
vector<string> answer;

int main(void)
{
    string name;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> name;
        person.insert({name, 1});
    }

    for(int i = 0; i < M; i++)
    {
        cin >> name;
        if(person[name] != 0) answer.push_back(name);
    }

    sort(answer.begin(), answer.end());
    int len = answer.size();

    cout << len << "\n";
    for(int i = 0; i < len; i++)
    {
        cout << answer[i] << "\n";
    }
}