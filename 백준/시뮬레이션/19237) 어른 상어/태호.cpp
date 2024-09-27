#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;


struct FSharkInfo
{
    int x, y, num, dir;
};

int n, m, k, seconds = 0;

int sharkBoard[22][22];
vector<FSharkInfo> sharkInfo;
vector<FSharkInfo> sharkPos;
vector<int> sharkPriority[404][4];
int sharkDir[404];
int smell[22][22];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void Input()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> sharkBoard[i][j];

            if (sharkBoard[i][j])
            {
                smell[i][j] = k;
                sharkInfo.push_back({i, j, sharkBoard[i][j] - 1 });
            }
        }
    }

    sort(sharkInfo.begin(), sharkInfo.end(), [](const FSharkInfo& a, const FSharkInfo& b){
        return a.num < b.num;
    });


    for(int i = 0; i < m; ++i)
    {   
        cin >> sharkDir[i];
        --sharkDir[i];
    }

    for (int i = 0; i < m; ++i)
    {
        for (int dir = 0; dir < 4; ++dir)
        {
            for (int pri = 0; pri < 4; ++pri)
            {
                int tmp; cin >> tmp;
                sharkPriority[i][dir].push_back(tmp - 1);
            }

        }
    }
}

void Search_Pos(int x, int y, int num, const vector<int>& Info, bool& flag)
{
    // 냄새가 없는 곳을 탐색
    for (int i = 0; i < Info.size(); ++i)
    {
        int nx = dx[Info[i]] + x;
        int ny = dy[Info[i]] + y;

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (smell[nx][ny]) continue;

        sharkPos.push_back({ nx, ny, num ,Info[i]});
        flag = true;
        break;
    }
}

void Search_Smell(int x, int y, int num, const vector<int>& Info, bool flag)
{
    // 냄새가 없는 곳을 못찾았다면?
    if (!flag)
    {
        // 내 냄새가 나는 곳을 탐색
        for (int i = 0; i < Info.size(); ++i)
        {
            int nx = dx[Info[i]] + x;
            int ny = dy[Info[i]] + y;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (sharkBoard[nx][ny] != sharkBoard[x][y]) continue;

            sharkPos.push_back({ nx, ny, num, Info[i] });
            break;
        }
    }
}

void SharkMove()
{
    // 사용한 정보들을 없애주자.
    sharkPos.clear();

    for (int i = 0; i < sharkInfo.size(); ++i)
    {
        auto[x, y, num, tmp] = sharkInfo[i];
        bool flag = false;

        const vector<int>& Info = sharkPriority[num][sharkDir[num]];
        
        Search_Pos(x, y, num, Info, flag);
        Search_Smell(x, y, num, Info, flag);
    }
}

void SubStractSmell()
{
    // 현재 냄새를 1씩 지운다.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (sharkBoard[i][j])
            {
                if (!(--smell[i][j]))
                    sharkBoard[i][j] = 0;
            }
        }
    }
}

void SharkOut()
{
    // 상어의 정보들을 초기화 시켜주고
    sharkInfo.clear();

    // 번호가 작은 것부터 들어갈 수 있도록 설정(정렬된 상태)
    for (int i = 0; i < sharkPos.size(); ++i)
    {
        auto[x, y, num, dir] = sharkPos[i];

        // 0이 아니고(냄새가 있고), 현재 인덱스와 상어가 같지 않다면 추가 X
        if(sharkBoard[x][y] != 0 && sharkBoard[x][y] != num + 1) 
            continue;

        sharkDir[num] = dir;
        sharkBoard[x][y] = num + 1;
        smell[x][y] = k;
        sharkInfo.push_back({x, y, num});
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();

    while (sharkInfo.size() != 1 && seconds <= 1000)
    {
        ++seconds;
        SharkMove();
        SubStractSmell();
        SharkOut();
    }
    if(seconds > 1000)
        cout << -1;
    else
        cout << seconds;


    return 0;
}
