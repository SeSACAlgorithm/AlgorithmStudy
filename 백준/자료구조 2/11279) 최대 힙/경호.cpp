#include <iostream>
#include <vector>

using namespace std;

class priority_queue
{
public:
    priority_queue()
    {
        _data = new uint32_t[1];
        _count = 0;
        _capacity = 1;
    }

    ~priority_queue()
    {
        delete[] _data;
    }

private:
    uint32_t* _data;
    int _count;
    int _capacity;

    void expand()
    {
        _capacity *= 2;
        uint32_t* new_data = new uint32_t[_capacity];
        for (int i = 0; i < _count; ++i)
            new_data[i] = _data[i];

        swap(_data, new_data);
        delete[] new_data;
    }

    void add(uint32_t value)
    {
        _data[_count] = value;
        _count++;

        int cur = _count - 1;
        while(cur > 0)
        {
            int parent = (cur - 1) / 2;
            if (_data[cur] < _data[parent])
                break;

            swap(_data[cur], _data[parent]);
            cur = parent;
        }
    }

    void remove()
    {
        _count--;
        _data[0] = _data[_count];
        _data[_count] = 0;

        int cur = 0;
        while(cur < _count)
        {
            int left = cur * 2 + 1;
            int right = cur * 2 + 2;
            int next = cur;

            if (left < _count && _data[left] > _data[next]) next = left;
            if (right < _count && _data[right] > _data[next]) next = right;
            if (next == cur) break;

            swap(_data[cur], _data[next]);
            cur = next;
        }
    }

public:
    void push(uint32_t value)
    {
        if (_count == _capacity)
            expand();
        add(value);
    }

    void pop()
    {
        if (empty()) return;

        remove();
    }

    uint32_t front() const { return _data[0]; }
    bool empty() const { return _count == 0; }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    uint32_t input;
    priority_queue pq;
    vector<uint32_t> answer;
    for(int i = 0; i < N; ++i)
    {
        cin >> input;

        if (input == 0)
        {
            if (pq.empty())
                answer.push_back(0);
            else
            {
                answer.push_back(pq.front());
                pq.pop();
            }
        }
        else
            pq.push(input);
    }

    for (const uint32_t& ans : answer)
        cout << ans << "\n";
}