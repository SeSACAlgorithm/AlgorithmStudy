#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0)
        return cities.size() * 5;
    
    int answer = 0;
    vector<string> cache;
    for(int i = 0; i < cities.size(); i++)
        for(int j = 0; j < cities[i].size(); j++)
            cities[i][j] = toupper(cities[i][j]);
    
    for(int i = 0; i < cities.size(); i++)
    {
        //cache hit
        auto it = find(cache.begin(), cache.end(), cities[i]);
        if(it != cache.end())
        {
            cache.erase(it, it + 1);
            cache.emplace_back(cities[i]);
            answer++;
        }
        else
        {
            //cache miss
            if(cache.size() == cacheSize)
                cache.erase(cache.begin(), cache.begin() + 1);
            cache.emplace_back(cities[i]);
            answer += 5;
        }
    }
    
    return answer;
}