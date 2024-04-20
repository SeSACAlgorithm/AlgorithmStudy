#include <string>
#include <vector>

using namespace std;

/*
    1. 알파벳 맞는 지 확인
        1) 만약 A라면 패스하기

    2. <- -> 최소 비교 후 대입
    
        1) 재귀를 이용해서 <- 와 -> 를 계산
        
        2) ZZAAAAAAAAZZ 와 같이 오른쪽을 순회 후 다시 왼쪽으로 가는 것 까지 계산해서 재귀를 이용하자. 
          ** 이때 주의해야 할 점 **
            -> 다시 왼쪽이나 오른쪽으로 갈 때 알파벳 계산을 해주지 말아야 한다. (본문은  if (JoyStick[idx] != name[idx]) 로 막아놓음)
          
        3) base condition은 size() - 1 로 설정 
          -> 어차피 size() - 1 정도면 그냥 오른쪽으로 가거나 왼쪽으로 가는 게 시간 상 이득이기 때문.

    2. 위, 아래 최소 비교 후 대입
        이건 완전 탐색?
*/

string alphabat = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int CheckUpDown(char searchAlpabat, bool up)
{
    int cnt = 0;

    if (up)
    {
        while (alphabat[cnt] != searchAlpabat)
            ++cnt;
    }
    else
    {
        int size = alphabat.size();
        cnt = size;

        while (alphabat[cnt] != searchAlpabat)
            --cnt;

        cnt = size - cnt;
    }

    return cnt;
}

void MoveJoyStick(const string& name, string JoyStick, int idx, int cnt, int ans, int& result)
{
    if (cnt == name.size())
        return;

    if (idx == -1)
        idx = name.size() - 1;
    else if (idx == name.size())
        idx = 0;

    if (JoyStick[idx] != name[idx])
    {
        int up = CheckUpDown(name[idx], true);
        int down = CheckUpDown(name[idx], false);

        JoyStick[idx] = name[idx];

        up < down ? ans += up : ans += down;
    }

    if (JoyStick == name)
    {
        result = min(ans, result);
        return;
    }

    MoveJoyStick(name, JoyStick, idx - 1, cnt + 1, ans + 1, result);
    MoveJoyStick(name, JoyStick, idx + 1, cnt + 1, ans + 1, result);
}


int solution(string name) {
    int answer = 2100000000;

    string JoyStick = "A";

    for (int i = 1; i < name.size(); ++i)
        JoyStick += "A";

    MoveJoyStick(name, JoyStick, 0, 0, 0, answer);
    
    return answer;
}
