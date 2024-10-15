#define GRID_SIZE 5

#include <iostream>
#include <string>
#include <map>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int gird[GRID_SIZE][GRID_SIZE];

map<string, bool> nums_group;
string nums = "";

void input()
{
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            cin >> gird[i][j];
        }
    }
}

void dfs(int x, int y, int index)
{
    if(index == 6) 
    {
        nums_group.insert({nums, true});
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= GRID_SIZE || ny >= GRID_SIZE) continue;

        nums.push_back(gird[x][y] + '0');
        dfs(nx,ny,index+1);
        nums.pop_back();
    }
}

int main(void)
{
    input();

    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            dfs(i,j,0);
        }
    }

    cout << nums_group.size();
}