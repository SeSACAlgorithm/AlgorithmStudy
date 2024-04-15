#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    for (int i = 0; i < completion.size(); i ++)
    {
        if (participant[i] != completion[i]) return participant[i];

    }
    return participant[participant.size()-1];
}

int main(int argc, char* argv[])
{
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    cout << solution(participant, completion);
}
