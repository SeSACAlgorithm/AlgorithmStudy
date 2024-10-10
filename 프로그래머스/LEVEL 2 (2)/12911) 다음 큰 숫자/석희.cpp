#include <string>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

int count_one(string str)
{
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '1') count++;
    }
    return count;
}

int solution(int n) {
    bitset<16> temp_n(n);
    int count_one_n = count_one(temp_n.to_string());
    
    for(int i = n + 1; i <= 1000000; i++)
    {
        bitset<16> temp(i);
        if(count_one(temp.to_string()) == count_one_n) return i;
    }
    
    return 0;
}