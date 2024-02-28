#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    // step 1
    for(int i = 0; i < new_id.size(); i++)
        if(new_id[i] >= 'A' && new_id[i]<= 'Z')
            new_id[i] = tolower(new_id[i]);
    // step 2
    for(int i = new_id.size() - 1; i >= 0; i--)
    {
        if(new_id[i] >= 'a' && new_id[i]<= 'z')
            continue;
        if(isdigit(new_id[i]))
            continue;
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            continue;
        // erase
        new_id.erase(new_id.begin() + i);
    }
    // step 3
    bool period = false;
    for(int i = new_id.size() - 1; i >= 0; i--)
    {
        if(new_id[i] != '.')
        {
            period = false;
            continue;
        }
        
        if(false == period)
            period = true; 
        else
           new_id.erase(new_id.begin() + i);
    }
    // step 4
    if(*(new_id.begin()) == '.')
        new_id.erase(new_id.begin());
    if(*(new_id.end() - 1) == '.')
        new_id.erase(new_id.end() - 1);
    // step 5
    if(new_id.empty())
        new_id = "a";
    // step 6
    if(new_id.size() > 15)
        new_id = new_id.substr(0, 15);
    if(*(new_id.end() - 1) == '.')
        new_id.erase(new_id.end() - 1);
    // step 7
    if(new_id.size() < 3)
    {
        char last = *(new_id.end() - 1);
        for(int i = new_id.size(); i < 3; i++)
            new_id += last;
    }
    return new_id;
}