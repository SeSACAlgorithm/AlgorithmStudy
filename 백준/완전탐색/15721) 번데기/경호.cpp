#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int people, target, order;
    cin >> people >> target >> order;

    int bbun_count = 0;
    int degi_count = 0;
    int rotate = 1, idx = 0;

    int answer = 0;
    for(int cur = 0; cur < people;)
    {
        if(idx < 4)
        {
            if (idx % 2 == 0) ++bbun_count;
            else              ++degi_count;
        }
        else
        {
            int half = rotate + 1;
            if(idx - 4 < half) ++bbun_count;
            else               ++degi_count;
        }

        bool bbun_complete = (order == 0) && (bbun_count == target);
        bool degi_complete = (order == 1) && (degi_count == target);
        if(bbun_complete || degi_complete)
        {
            answer = cur;
            break;
        }

        cur = (cur + 1) % people;
        int limit = rotate * 2 + 6;
        if(++idx == limit)
        {
            idx = 0;
            ++rotate;
        }
    }

    cout << answer;
}