#include <string>
using namespace std;

// 길에 대해 UDRL 3차원 배열 생성
// 안가본 길에 대해서만 결과값을 ++ 해주자

string coordinate = "ULDR";

unordered_set<pair<int, int>> freq;

int toDir(int dir)
{
    return (dir + 2) % 4;
}

void moves(int op)
{
    int nx = posX + dx[op];
    int ny = posY + dy[op];

    if (nx < 0 || ny < 0 || nx > 10 || ny > 10) return;


    if (!visited[posX][posY][op])
    {
        visited[posX][posY][op] = true;
        visited[nx][ny][toDir(op)] = true;
        ++answer;
    }

    posX = nx;
    posY = ny;
}

int solution(string dirs = "ULURRDLLU") {

    for (int i = 0; i < dirs.size(); ++i)
    {
        if (dirs[i] == coordinate[0])
            moves(0);
        else if (dirs[i] == coordinate[1])
            moves(1);
        else if (dirs[i] == coordinate[2])
            moves(2);
        else
            moves(3);
    }

    return answer;
}
