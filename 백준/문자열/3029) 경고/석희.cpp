#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> times[2]; // 현재 시간 & 나트륨 던질 시간
int answer[3];        // 기다려야 하는 시간

// 문자열을 : ':' 기준으로 나누어서 저장
// times[0]에는 현재 시간 / times[1]에는 던질 시간
void substr(string str, int index)
{
    int temp = 0;
    istringstream ss(str);
    string sub;

    while (getline(ss, sub, ':'))
    {
        temp = stoi(sub);
        times[index].push_back(temp);
    }
}

int main(void)
{
    string temp_time;
    string check_time = "";

    for (int i = 0; i < 2; i++)
    {
        cin >> temp_time;
        if (check_time == temp_time)
        {
            cout << "24:00:00";
            return 0;
        }
        check_time = temp_time;
        substr(temp_time, i);
    }

    for (int i = 2; i >= 0; i--)
    {
        // 던질 시간의 값보다 현재 시간의 값이 크다면
        if (times[0][i] > times[1][i])
        {
            // hh 라면
            if (i == 0)
            {
                times[1][i] += 24;
            }
            else
            {
                times[1][i] += 60;
                times[1][i - 1]--;
            }
        }
        answer[i] = times[1][i] - times[0][i];
    }

    for (int i = 0; i < 3; i++)
    {
        if (answer[i] < 10) cout << "0";
        cout << answer[i];

        if (i != 2) cout << ":";
    }
}