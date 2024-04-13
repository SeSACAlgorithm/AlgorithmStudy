#include <string>
#include <cmath>
#include <iostream>

#define NONE_NUM -99999999

using namespace std;


int pre = NONE_NUM, cur = NONE_NUM;
int answer = 0;
string s;

void Add(int num)
{
    if (pre != NONE_NUM)
        answer += pre;

    pre = cur;
    cur = num;

    s = "";
}

int solution(string dartResult) {

    for (int i = 0; i < dartResult.size(); ++i)
    {
        if (dartResult[i] == 'S')
        {
            Add(stoi(s));
        }
        else if (dartResult[i] == 'D')
        {
            Add(pow(stoi(s), 2));
        }
        else if (dartResult[i] == 'T')
        {
            Add(pow(stoi(s), 3));
        }
        else if (isdigit(dartResult[i]))
        {
            s += dartResult[i];
        }
        else if (dartResult[i] == '*')
        {
            if (cur != NONE_NUM)  cur *= 2;
            if (pre != NONE_NUM  pre *= 2;
        }
        else if (dartResult[i] == '#')
        {
            if (cur != NONE_NUM)  cur *= -1;
        }
    }

    if (cur != NONE_NUM)   answer += cur;
    if (pre != NONE_NUM)  answer += pre;

    return answer;
}
