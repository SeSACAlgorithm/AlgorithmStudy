#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    const string all_equal = "Equilateral";
    const string two_equal = "Isosceles";
    const string all_diff = "Scalene";
    const string invalid = "Invalid";

    vector<string> result;
    vector<int> lines(3, 0);
    while (true)
    {
        cin >> lines[0] >> lines[1] >> lines[2];

        if (lines[0] == 0)
            break;

        auto max_it = max_element(lines.begin(), lines.end());
        int sum = 0;
        for (auto it = lines.begin(); it != lines.end(); ++it)
            if (it != max_it)
                sum += *it;
        
        if (*max_it >= sum)
            result.push_back(invalid);
        else if(lines[0] == lines[1] && lines[0] == lines[2])
            result.push_back(all_equal);
        else if(lines[0] != lines[1] && lines[1] != lines[2] && lines[2] != lines[0])
            result.push_back(all_diff);
        else 
            result.push_back(two_equal);
    }
    
    for (const string& res : result)
        cout << res << "\n";
}