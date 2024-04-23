#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        string str(phone_book[i + 1].begin(), phone_book[i + 1].begin() + phone_book[i].size());

        if (phone_book[i] == str)
            return false;
    }

    return answer;
}


