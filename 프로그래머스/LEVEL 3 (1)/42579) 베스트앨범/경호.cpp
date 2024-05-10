#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct MusicData
{
    int index;
    int play_count;
    
    MusicData(int idx, int count) : index(idx), play_count(count) {}
};

inline bool operator<(const MusicData left, const MusicData right)
{
    if(left.play_count == right.play_count)
        return left.index > right.index;
    return left.play_count < right.play_count;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> count;
    map<string, priority_queue<MusicData>> genre_data;
    
    for(int i = 0; i < genres.size(); ++i)
    {
        count[genres[i]] += plays[i];
        genre_data[genres[i]].push(MusicData(i, plays[i]));
    }
    
    vector<pair<string, priority_queue<MusicData>>> results(genre_data.begin(), genre_data.end());
    sort(results.begin(), results.end(), 
         [&](pair<string, priority_queue<MusicData>> a, pair<string, priority_queue<MusicData>> b) 
         { return count[a.first] > count[b.first]; }
    );
    
    for(auto it = results.begin(); it != results.end(); ++it)
    {
        for(int i = 0; i < 2; ++i)
        {
            if(it->second.empty()) break;
            
            answer.emplace_back(it->second.top().index);
            it->second.pop();
        }
    }
    
    return answer;
}