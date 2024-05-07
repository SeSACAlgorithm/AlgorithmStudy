#include <string>
#include <vector>

using namespace std;

class PQ
{
private:
    int _count;
    int _capacity;
    vector<int> high;
    vector<int> low;
    
public:
    PQ()
    {
        _count = 0;
        _capacity = 1;
        high.push_back(0);
        low.push_back(0);
    }
    
private:
    void expand()
    {
        high.reserve(_capacity * 2);
        low.reserve(_capacity * 2);
        for (int i = high.size(); i < high.capacity(); i++)
        {
            high.push_back(0);
            low.push_back(0);
        }
        _capacity *= 2;
    }
    
    void add(int val)
    {
        high[_count] = val;
        low[_count] = val;
        ++_count;
        
        // high
        int cur = _count - 1, parent = 0;
        while(cur > 0)
        {
            parent = (cur - 1) / 2;
            
            if(high[cur] <= high[parent]) break;
            
            int temp = high[cur];
            high[cur] = high[parent];
            high[parent] = temp;
            cur = parent;
        }
        // low
        cur = _count - 1, parent = 0;
        while(cur > 0)
        {
            parent = (cur - 1) / 2;
            
            if(low[cur] >= low[parent]) break;
            
            int temp = low[cur];
            low[cur] = low[parent];
            low[parent] = temp;
            cur = parent;
        }
    }
    
public:
    void push(int val)
    {
        if(_count == _capacity)
            expand();
        add(val);
    }
    
    void pop_high()
    {
        if(_count == 0) return;
        
        --_count;
        high[0] = high[_count];
        high[_count] = 0;
        
        int cur = 0, parent = 0;
        int left = 0, right = 0, target = 0;
        while(cur < _count)
        {
            left = cur * 2 + 1;
            right = cur * 2 + 2;
            target = cur;
            if(left < _count && high[left] > high[target])
                target = left;
            if(right < _count && high[right] > high[target])
                target = right;
            if(target == cur) break;
            
            int temp = high[target];
            high[target] = high[cur];
            high[cur] = temp;
            cur = target;
        }
    }
    
    void pop_low()
    {
        if(_count == 0) return;
        
        --_count;
        low[0] = low[_count];
        low[_count] = 0;
        
        int cur = 0, parent = 0;
        int left = 0, right = 0, target = 0;
        while(cur < _count)
        {
            left = cur * 2 + 1;
            right = cur * 2 + 2;
            target = cur;
            if(left < _count && low[left] < low[target])
                target = left;
            if(right < _count && low[right] < low[target])
                target = right;
            if(target == cur) break;
            
            int temp = low[target];
            low[target] = low[cur];
            low[cur] = temp;
            cur = target;
        }
    }
    
    int peek_high() { return high[0]; }
    int peek_low() { return low[0]; }
    int size() { return _count; }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    PQ pq;
    
    for(const string& s : operations)
    {   
        if(s == "D 1")
            pq.pop_high();
        else if(s == "D -1")
            pq.pop_low();
        else
            pq.push(stoi(s.substr(2)));
    }
    
    return pq.size() > 0 ? vector<int>{ pq.peek_high(), pq.peek_low() } 
                         : vector<int>{ 0, 0 };
}