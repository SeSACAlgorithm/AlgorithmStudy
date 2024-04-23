#include <iostream>
#include <string>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    string eight;
    string two[8] = {"000","001","010","011","100","101","110","111"};

    cin>>eight;

    for(int i=0; i<eight.size(); i++)
    {
        int tmp = eight[i] - '0';

        // 맨 앞자리가 0인 경우 string을 integer로 변환 후 0 출력
        if(i == 0)
            cout<<stoi(two[tmp]);
        else
            cout<<two[tmp];
    }
}