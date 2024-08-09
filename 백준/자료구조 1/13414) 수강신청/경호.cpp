#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    cin >> K >> L;

    queue<string> wait_que;
    map<string, int> idx_map; // key: id, value: last idx
    string temp;
    for(int i = 0; i < L; ++i)
    {
        cin >> temp;
        wait_que.emplace(temp);
        idx_map[temp] = i;
    }

    int count = 0;
    for(int i = 0; i < L; ++i)
    {
        temp = wait_que.front();
        wait_que.pop();

        // 현재 인덱스가 해당 id로 시도한 가장 마지막 인덱스라면 추가
        if(idx_map[temp] == i)
        {
            cout << temp << "\n";
            ++count;
            if (count == K) break;
        }
    }
}