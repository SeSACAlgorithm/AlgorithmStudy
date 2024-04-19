#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int index = 0;

    for (int j = people.size() - 1; j >= 0; --j)
    {
		if(index > j) 
			break;

        int mylimit = people[index] + people[j];
        if (mylimit <= limit)
        {
            ++index;
        }

        ++answer;

    }

    return answer;
}
