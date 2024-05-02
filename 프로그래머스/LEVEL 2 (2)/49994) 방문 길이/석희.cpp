/*
-5, -5를 만들려면 string밖에 없는데 귀찮음..
어짜피 맵의 크기가 고정이니까 5,5를 원점이라고 생각
-> 방문한 점을 체크하는게 아니라 "간선"을 체크하는거니까 4방향 다 다른 경우
5,5에서 올라가는 길 = 4,5에서 내려가는 길 이므로 둘다 체크해야함!

+ 다른 풀이
=> Set을 사용해서 중복처리하는 풀이
=> 방향을 추가하지 않고 4차원 배열 선언해서 그 경우를 체크하는 풀이 ex) visit[5][5][4][5] = visit[4][5][5][5]= true
*/

#include <string>
using namespace std;

bool visit[11][11][4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int solution(string dirs) {
    int answer = 0;

    // 원점을 5,5 라고 생각
    int x = 5;
    int y = 5;

    int road = 0;
    int next_road = 0;

    for(int i = 0; i < dirs.size(); i++)
    {
        switch (dirs[i])
        {
        case 'U':
            road = 0;
            next_road = 1;
            break;

        case 'D':
            road = 1;
            next_road = 0;
            break;

        case 'R':
            road = 2;
            next_road = 3;
            break;

        case 'L':
            road = 3;
            next_road = 2;
            break;
        
        default:
            break;
        }

        int nx = x + dx[road];
        int ny = y + dy[road];

        if(nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;

        if(!visit[x][y][road] && !visit[nx][ny][next_road])
        {
            visit[x][y][road] = true;
            visit[nx][ny][next_road] = true;
            answer++;
        }

        x = nx;
        y = ny;
    }

    return answer;
}