#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Rank(int win){
    if(win == 6) return 1;
    else if(win == 5) return 2;
    else if(win == 4) return 3;
    else if(win == 3) return 4;
    else if(win == 2) return 5;
    else if(win == 1) return 6;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> ans;
    int win;
    int zero = count(lottos.begin(), lottos.end(), 0);
    
    for(int i : lottos)
        if(find(win_nums.begin(), win_nums.end(), i) != win_nums.end())
            win++;
    
    ans.push_back(Rank(win+zero));
    ans.push_back(Rank(win));
    
    return ans;
}
