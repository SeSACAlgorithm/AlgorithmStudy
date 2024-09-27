#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;

    cin >> n >> k;

    // 1. 학생들이 추천을 시작하기 전에 모든 사진틀은 비어있다.
    unordered_map<int, pair<int, int>> frame;

    for (int i = 0; i < k; ++i)
    {
        int ddabbong; cin >> ddabbong;

        if (frame.size() == n)
        {
            /*
                3. 비어있는 사진틀이 없는 경우에는 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고,
                그 자리에 새롭게 추천받은 학생의 사진을 게시한다.
                이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는
                그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
            */

            int recommand = 0x7f7f7f7f;
            int key = -1;    
            int num = -1;
            
            if (frame.find(ddabbong) != frame.end())
            {
                ++frame[ddabbong].first;
                continue;
            }
               

            for (auto elem : frame)
            {
                if (recommand > elem.second.first)
                {
                    num = elem.second.second;
                    recommand = elem.second.first;
                    key = elem.first;
                }
                else
                {
                    if (recommand == elem.second.first && num > elem.second.second)
                    {
                        num = elem.second.second;
                        recommand = elem.second.first;
                        key = elem.first;
                    }
                }


            }

            // 5. 사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.
            frame.erase(key);
        }

        // 2. 어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
        if (frame.find(ddabbong) == frame.end())
            frame[ddabbong].second = i;
        
        // 4. 현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
        ++frame[ddabbong].first;


    }

    vector<int> result;

    for(auto elem : frame)
        result.push_back(elem.first);

    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << ' ';

    return 0;
}
