#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
bool vis[10];

struct Banned_Player
{
    string user_id;
    vector<int> asteriskPoint;
    int idx;
};

vector<Banned_Player> banned;
vector<vector<int>> VS;

void func(const vector<string>& user_id, int k)
{
    if(banned.size() == k)
    {
		vector<int> V;

		for(int i = 0; i < 10; ++i)
		{
            if(vis[i])
            {
                V.push_back(i);
                if(V.size() == k)
					break;
            }
		}

        sort(V.begin(), V.end());

        bool bSame = false;

        for(int i = 0; i < VS.size(); ++i)
        {
            if(VS[i] == V)
            {
                bSame = true;
                break;
            }
        }

        if(!bSame)
        {
            VS.push_back(V);
            ++answer;
        }
		

		
	    return;
    }

    for(int i = 0; i < user_id.size(); ++i)
    {
		bool bSame = true;

        if (vis[i] || user_id[i].size() != banned[k].user_id.size()) continue;

        for(int elem : banned[k].asteriskPoint)
        {

            if(user_id[i][elem] != banned[k].user_id[elem])
            {
                bSame = false;
                break;
            }
        }

        if(bSame)
        {
            vis[i] = true;
            func(user_id, k + 1);
            vis[i] = false;
        }
            
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {

	for(int i = 0; i < banned_id.size(); ++i)
	{
        banned.push_back({ banned_id[i], vector<int>(), i});

        for(int j = 0; j < banned_id[i].size(); ++j)
        {
	        if(banned_id[i][j] != '*')
	        {
                banned[i].asteriskPoint.push_back(j);
	        }
               
				
        }
	}

    func(user_id, 0);

    return answer;
}
