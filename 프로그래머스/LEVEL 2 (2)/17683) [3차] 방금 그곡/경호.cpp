#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct MusicData
{
    int origin_idx = 0;
    int minutes = 0;
    string name = "";
    string codes = "";
    
    MusicData() {}
    
    MusicData(int idx, int m, const string& n, const string& c)
    {
        origin_idx = idx;
        minutes = m;
        name = n;
        codes = c;
    }
};

string encoder(const string& str)
{
    string res = "";
    int limit = str.size() - 1;
    for(int i = 0; i < limit; )
    {
        if(str[i + 1] == '#')
        {
            res += tolower(str[i]);
            i += 2;
        }
        else
        {
            res += str[i];
            ++i;
        }
    }
    if(str.back() != '#') res += str.back();
    return res;
}

int get_minutes(const string& s1, const string& s2)
{
    int h1 = stoi(s1.substr(0, 2)), h2 = stoi(s2.substr(0, 2));
    int m1 = stoi(s1.substr(3, 2)), m2 = stoi(s2.substr(3, 2));
    return (h2 * 60 + m2) - (h1 * 60 + m1);
}

string get_name(const string& s)
{
    for(int i = 12; i < s.size(); ++i)
    {
        if(s[i] == ',')
            return s.substr(12, i - 12);
    }
    return "";
}

string solution(string m, vector<string> musicinfos) {
    map<string, MusicData> musics;
    m = encoder(m);
    
    int minutes = 0, code_idx = 0;
    string name = "", codes = "";
    for(int i = 0; i < musicinfos.size(); ++i)
    {
        minutes = get_minutes(musicinfos[i].substr(0, 5), musicinfos[i].substr(6, 5));
        name = get_name(musicinfos[i]);
        code_idx = 12 + name.size() + 1;
        codes = encoder(musicinfos[i].substr(code_idx, musicinfos[i].size() - code_idx));
        
        string tmp = "";
        for(int i = 0; i < minutes; ++i)
            tmp += codes[i % codes.size()];
        
        musics[name] = MusicData(i, minutes, name, tmp);
    }
    
    vector<MusicData> answer;
    int f_idx = 0;
    for(auto it = musics.begin(); it != musics.end(); ++it)
    {
        f_idx = it->second.codes.find(m);
        if(f_idx > -1)
            answer.emplace_back(it->second);
    }
    
    if(answer.empty()) return "(None)";
    
    sort(answer.begin(), answer.end(), [](MusicData a, MusicData b)
    {
        if(a.minutes != b.minutes)
            return a.minutes > b.minutes;
        return a.origin_idx < b.origin_idx;
    });
    return answer[0].name;
}