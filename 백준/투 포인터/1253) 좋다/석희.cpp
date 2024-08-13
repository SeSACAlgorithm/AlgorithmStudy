#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

void input()
{
    int num = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
}

bool check_good_num(int index)
{
    int left = 0;
    int right = N - 1; // arr.size() - 1

    while(left < right)
    {
        if(arr[left] + arr[right] == arr[index])
        {
            if(left != index && right != index) return true;
            else if(left == index) left++;
            else if(right == index) right--;
        }
        else if(arr[left] + arr[right] < arr[index]) left++;
        else right--;
    }

    return false;
}

void solve()
{
    int answer = 0;

    sort(arr.begin(), arr.end(), less<int>());
    for (int i = 0; i < arr.size(); i++)
    {
        if (check_good_num(i))
            answer++;
    }

    cout << answer;
}

int main(void)
{
    input();
    solve();
}