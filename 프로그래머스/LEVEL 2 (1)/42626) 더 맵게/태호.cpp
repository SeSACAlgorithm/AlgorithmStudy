int solution(vector<int> scoville, int K) {
    int answer = 0;
    int size = scoville.size();

    multiset<int> MS;

    for(int i = 0; i < scoville.size(); ++i)
        MS.insert(scoville[i]);


    while (MS.size() > 1)
    {
        if (K <= *MS.begin())
            break;

        ++answer;

        int n = *MS.begin() + *(++MS.begin()) * 2;
        MS.erase(MS.begin());
        MS.erase(MS.begin());
        MS.insert(n);
    }

    if(MS.size() == 1)
    {
        if (K > *MS.begin())
            return -1;
    }


    return answer;
}
