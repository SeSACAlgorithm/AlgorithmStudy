#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
map<int, bool> nums;        // 맵 확인용
vector<int> bs_nums;        //  이진 탐색용

void FindMap()
{
    int num, check;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        nums[num] = true;
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> check;
        if(nums[check]) cout << "1 ";
        else cout << "0 "; 
    }
}

bool BinarySearch(int target)
{
    int left = 0;
    int right = N - 1;
    int mid;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(bs_nums[mid] == target) return true;

        if(bs_nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

void FindBsInput()
{
    int num, check;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        bs_nums.push_back(num);
    }

    sort(bs_nums.begin(), bs_nums.end());

    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> check;
        if(BinarySearch(check)) cout << "1 ";
        else cout << "0 "; 
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    //FindMap();          // 맵으로 푼 경우
    FindBsInput();      // 이진탐색으로 푼 경우
}

