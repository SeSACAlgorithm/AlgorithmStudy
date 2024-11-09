#include <iostream>
#include<map>
using namespace std;

int main()
{
	map<string, int> book;
	int len, max = 0;;
	string res,str;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> str;
		book[str]++; //책의 갯수 측정
	}

	for (auto curBook : book)
	{
		if (curBook.second >= max) //가장 큰 책의 갯수를 찾음
		{
			max = curBook.second;
			res = curBook.first;
		}
	}
	cout << res;
}
출처: https://ohsol.tistory.com/entry/백준-1302-베스트셀러-C풀이 [오솔의 블로그:티스토리]
