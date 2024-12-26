#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool cantMix[201][201] = {false, };

vector<int> icecreams;
int answer = 0;

void Input()
{
    cin >> N >> M;

    int ice1, ice2;
    for(int i = 0; i < M; i++)
    {
        cin >> ice1 >> ice2;
        cantMix[ice1][ice2] = true;
        cantMix[ice2][ice1] = true;
    }
}


bool FindCanMix(int ice1, int ice2, int ice3)
{
    if(cantMix[ice1][ice2]) return false;
    if(cantMix[ice2][ice3]) return false;
    if(cantMix[ice1][ice3]) return false;
    return true;
}

void FindMix(int index, int now)
{
    if(index == 3)
    {
        if(FindCanMix(icecreams[0], icecreams[1], icecreams[2])) answer++;
        return;
    }

    for(int i = now; i <= N; i++)
    {
        icecreams.push_back(i);
        FindMix(index+1, i+1);
        icecreams.pop_back();
    }
}

int main(void)
{
    Input();
    FindMix(0, 1);
    cout << answer;
}