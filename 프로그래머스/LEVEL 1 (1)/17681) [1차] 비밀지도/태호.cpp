#include <string>
#include <vector>
#include <cmath>

using namespace std;

string arr[20];

void bfs(vector<int> arr1, int n)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        int two = arr1[i];
        string temp = "";

        for (int j = n - 1; j >= 0; --j)
        {
            int k = pow(2, j);

            if (two >= k)
            {
                temp += '1';
                two -= k;
            }
            else
                temp += '0';
        }

        for (int j = 0; j < temp.size(); ++j)
        {
            if (temp[j] == '1' && arr[i][j] == '0')
                arr[i][j] = '1';
        }
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            arr[i] += "0";

    bfs(arr1, n);
    bfs(arr2, n);

    for (int i = 0; i < n; ++i)
    {
        answer.push_back("");
        for (int j = 0; j < n; ++j)
        {
            answer.back() += (arr[i][j] == '1' ? '#' : ' ');
        }
    }


    return answer;
}
