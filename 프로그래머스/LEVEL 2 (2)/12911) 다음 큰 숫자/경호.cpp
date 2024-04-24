using namespace std;

int one_count(int num)
{
    int count = 0;
    while(num > 1)
    {
        if((num & 1) == 1) ++count;
        num = num >> 1;
    }
    return count;
}

int solution(int n) {
    int answer = n + 1;
    int count = one_count(n);
    
    while(true)
    {
        if(one_count(answer) == count)
            break;
        ++answer;
    }
    
    return answer;
}