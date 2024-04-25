#include <string>
#include <algorithm>

string numbers = "0123456789ABCDEF";

string solution(int n, int t, int m, int p) {
    string answer = "";
    string source = "0";

    for (int i = 1; i < t * m; ++i)
    {
        int k = i;
        string str = "";
	    while (k)
	    {
            str += numbers[k % n];
            k /= n;
	    }

        reverse(str.begin(), str.end());
        source += str;
    }

    for(int i = p - 1; i < t * m; i += m)
        answer += source[i];

    return answer;
}
