#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer = "";

    vector<char> vecChar;
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= 3; ++j)
            vecChar.push_back(char(3 * i + j) + '0');

    vecChar.push_back('*');
    vecChar.push_back('0');
    vecChar.push_back('#');

    int left = 9;
    int right = 11;

    set<int> LeftNum;
    for(int i = 0; i < 8; i += 3)
        LeftNum.insert(i);

    set<int> RightNum;
    for (int i = 2; i < 9; i += 3)
        RightNum.insert(i);


    int axis[4] = {-1,1,-3,3};

    for (int i = 0; i < numbers.size(); ++i)
    {
        if (--numbers[i] == -1)
            numbers[i] = 10;

        if (LeftNum.end() != LeftNum.find(numbers[i]))          
        {
            left = numbers[i];
            answer += "L";
        }
        else if(RightNum.end() != RightNum.find(numbers[i]))
        {
            right = numbers[i];
            answer += "R";
        }
        // 가운데 있을 경우  2, 5, 8, 10 [1], [4], [7], [10]
        // {-1, 1, 0, 0}
        // {0 ,0, -3, 3}
        else
        {
            queue<int> Q1;
            int dist1[12];
            fill(dist1, dist1 + 12, 0);
            Q1.push(left);
            dist1[left] = 1;



            while (dist1[numbers[i]] == 0)
            {
                auto cur = Q1.front(); Q1.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = axis[dir] + cur;
                    if(nx >= 12 || nx < 0) continue;
                    if(dist1[nx] > 0) continue;
                    dist1[nx] = dist1[cur] + 1;
                    Q1.push(nx);
                }
            }

            queue<int> Q2;
            int dist2[12];
            fill(dist2, dist2 + 12, 0);
            Q2.push(right);
            dist2[right] = 1;

            while (dist2[numbers[i]] == 0)
            {
                auto cur = Q2.front(); Q2.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = axis[dir] + cur;
                    if (nx >= 12 || nx < 0) continue;
                    if (dist2[nx] > 0) continue;
                    dist2[nx] = dist2[cur] + 1;
                    Q2.push(nx);
                }
            }


            if (dist1[numbers[i]] < dist2[numbers[i]])
            {

                left = numbers[i];
                answer += "L";
            }
            else if (dist1[numbers[i]] > dist2[numbers[i]])
            {
                right = numbers[i];
                answer += "R";
            }
            else if (dist2[numbers[i]] == dist1[numbers[i]])
            {
                if (hand == "right")
                {
                    right = numbers[i];
                    answer += "R";
                }
                else
                {
                    left = numbers[i];
                    answer += "L";
                }
            }
        }
    }

    return answer;
}
