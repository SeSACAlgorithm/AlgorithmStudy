#include <string>
#include <vector>

using namespace std;

string solution( string s ) {
	int n = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			n = 0;
			continue;
		}

		s[i] = n % 2 == 0 ? s[i] = toupper( s[i] ) : s[i] = tolower( s[i] );

		//if (n % 2 == 0)
		//	s[i] = toupper( s[i] );

		//else
		//	s[i] = tolower( s[i] );

		n++;
	}
	return s;
}
