#include <string>

using namespace std;

string solution(string phone_number) {
    int limit = phone_number.size() - 4;
    for(int i = 0; i < limit; i++)
        phone_number[i] = '*';
    
    return phone_number;
}