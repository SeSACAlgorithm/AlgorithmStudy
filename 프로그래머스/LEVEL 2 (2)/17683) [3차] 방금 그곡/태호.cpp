#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Music
{
    int startTime;
    int endTime;
    string SongName;
    string Melody;
};

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    // "C# D# F# G# A#

    enum IDX
    {
        IDX_START,
        IDX_END,
        IDX_SONG,
    };

    vector<Music> vecMusic;

    for(int i = 0; i < musicinfos.size(); ++i)
    {
	    string str = "";
        bool start = true;
        IDX idx = IDX_START;
        Music music;

        for(int j = 0; j < musicinfos[i].size(); ++j)
        {
            if (musicinfos[i][j] == ':')
            {
                if(start)
                {
                    music.startTime = stoi(str) * 60;
                    start = false;
                }
                else
                {
                    music.endTime = stoi(str) * 60;
                }

                str = "";
            }
            else if (musicinfos[i][j] == ',')
            {
	            switch (idx)
            	{
	            case IDX_START:
                    music.startTime += stoi(str);
					break;
	            case IDX_END:
                    music.endTime += stoi(str);
					break;
	            case IDX_SONG:
                    music.SongName = str;
					break;
	            }

                str = "";
                idx = IDX(int(idx) + 1);
            }
            else
            {
                str += musicinfos[i][j];
            }
        	
        }

        if(!str.empty())
            music.Melody = str;
            

        vecMusic.push_back(music);
    }

    int mxSize = 0;
	for(int i = 0; i < vecMusic.size(); ++i)
	{
        if(vecMusic[i].startTime >= vecMusic[i].endTime)
	        continue;

        int curTime = vecMusic[i].endTime - vecMusic[i].startTime;
        vector<string> vec;

        for(int j = 0; j < vecMusic[i].Melody.size(); ++j)
        {
            string str = "";
            str += vecMusic[i].Melody[j];

            if(vecMusic[i].Melody[j] == '#')
                vec[vec.size() - 1] += str;
            else
                vec.push_back(str);
        }


        int MelSize = vec.size();
        string str = "";

        while (curTime >= MelSize)
        {
			for(int j = 0; j < MelSize; ++j)
                str += vec[j];

            curTime -= MelSize;
        }

        if(curTime > 0)
        {
	        for(int j = 0; j < curTime; ++j)
	        {
                str += vec[j];
	        }
        }
        
        int strsize = 0;
        for(int j = 0; j < str.size(); ++j)
        {
	        if(str[j] != '#')
		        ++strsize;
        }

        bool bfind = false;
        while (!str.empty())
        {
            int k = str.find(m);

            if(k == -1)
				break;

            int size = str.size();

            if (str.size() >= k + m.size())
            {
                if(str[k + m.size()] == '#')
                {
                    str.erase(str.begin() + k, str.begin() + k + m.size() + 1);
                }
                else
                {
                    bfind = true;
                    break;
                }
					
            }
        }
 

        if(bfind)
        {
	        if(mxSize < strsize)
	        {
                mxSize = strsize;
                answer = vecMusic[i].SongName;
	        }
        }

	}
    
    if(answer.empty())
        return "(None)";

    return answer;
}
