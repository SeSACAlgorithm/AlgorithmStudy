#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

enum EDirection
{
    None,
    Up,
    Down,
    Right,
    Left
};

struct FShark
{
    int speed;
    int direction;
    int size;
};


int r, c, m, result = 0;
FShark boardBase[101][101] = { 0, 0, 0 };
FShark boardSub[101][101] = {0, 0, 0};
map<pair<int, int>, FShark> shark;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> m;

    for (int i = 0; i < m; ++i)
    {
        int x, y, s, d, z; 
        cin >> x >> y >> s >> d >> z;

        // 0 based 를 위한 --연산 수행
        // 1 based 로 코드를 작성한다면 필요 X
        --x; --y;

        if (d == Right)
        {
            if (y == c - 1)
                d = Left;
        }
        else if (d == Left)
        {
            if (y == 0)
                d = Right;
        }
        else if (d == Up)
        {
            if (x == 0)
                d = Down;
        }
        else if (d == Down)
        {
            if (x == r - 1)
                d = Up;
        }

        // 격자 안에 상어의 정보를 저장
        boardBase[x][y] = {s, d, z};

        shark.insert({{x, y}, {s, d, z}});
    }

    int cycle = 0;

    // 낚시왕이 행을 움직이면서 열에 있는 상어를 잡아먹는 사이클을 만들었다.
    while (cycle != c)
    {

        // 낚시왕이 1행에 도착했을 때 1행에 가장 가까운 열의 상어를 잡는다.
        for (int i = 0; i < r; ++i)
        {
            // 상어의 크기는 1이상이기 때문에 격자판에 없다는 것으로 간주된다.
            if(!boardBase[i][cycle].size) continue;

            // 상어의 크기를 저장
            result += boardBase[i][cycle].size;

            // 상어를 격자판에서 삭제시켜준다.
            boardBase[i][cycle] = {0, 0, 0};
            shark.erase({i, cycle});
            break;
        }

        // 상어의 위치와 크기를 저장한다.
        map<pair<int, int>, FShark> tmp;

        // 상어가 이동한다.
        for (auto iter = shark.begin(); iter != shark.end(); ++iter)
        {
            
            pair<int, int> pos = (*iter).first;
            auto[speed, dir, size] = (*iter).second;

            boardBase[pos.first][pos.second] = {0, 0, 0};
 

            // 방향에 따라 이동할 축이 다르므로 구분합니다.
            if (dir == Right || dir == Left) 
            {
                int modSpeed = speed % (2 * (c - 1));  // 주기적으로 이동

                for (int i = 0; i < modSpeed; ++i) 
                {
                    if (dir == Right) 
                    {
                        ++pos.second;

                        if (pos.second == c - 1) 
                            dir = Left;
                    }
                    else 
                    {
                        --pos.second;

                        if (pos.second == 0) 
                            dir = Right;
                    }
                }
            }
            else 
            {
                int modSpeed = speed % (2 * (r - 1));  // 주기적으로 이동

                for (int i = 0; i < modSpeed; ++i) 
                {
                    if (dir == Down) 
                    {
                        ++pos.first;

                        if (pos.first == r - 1) 
                            dir = Up;
                    }
                    else 
                    {
                        --pos.first;

                        if (pos.first == 0) 
                            dir = Down;
                    }
                }
            }


            auto sharkF = tmp.find(pos);

            if (sharkF != tmp.end())
            {
                if ((*sharkF).second.size < size)
                    (*sharkF).second = { speed, dir, size };
                    
            }
            else
                tmp.insert({ pos, { speed, dir, size } });
            
        }

        shark.clear();
        for (const auto& iter : tmp)
        {
            pair<int, int> pos = iter.first;
            FShark based = iter.second;

            boardBase[pos.first][pos.second] = based;
            shark.insert({ pos, based });
        }


        // 낚시왕이 오른쪽으로 한 칸 이동한다.(0행 -> 1행)
        ++cycle;
    }

    cout << result;

    return 0;
}
