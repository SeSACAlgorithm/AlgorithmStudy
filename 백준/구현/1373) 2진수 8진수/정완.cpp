#include <iostream>
#include <string>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    string s;
    cin>>s;

    while (s.length() % 3 != 0)     // 2진수가 3개 단위로 나눠지지 않으면 '0'을 추가해줘서 3의 배수로 끊기게
        s = '0' + s;

    for(int i=0; i<s.size(); i+=3)
    {
        int eight = (s[i] -'0')*4+(s[i+1] -'0')*2+(s[i+2] -'0');
        cout<< eight;
    }
}