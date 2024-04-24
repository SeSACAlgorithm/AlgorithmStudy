#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;

    for (int i = 0; i < progresses.size(); ++i)
    {
        int k = progresses[i];
        int num = 0;
        while (k < 100)
        {
            k += speeds[i]; //60 90 120
            ++num; // 1 2 3
        }

        Q.push(num);
    }

    // 7 3 9 

    int k = 0;
    int index = -1;
    
    while (!Q.empty())
    {
       int a = Q.front();

       if (k < a)
       {
           k = a;
           answer.push_back(1);
           ++index;
       }
       else
       {
           ++answer[index];
       }

       Q.pop();
    }

    return answer;
}
