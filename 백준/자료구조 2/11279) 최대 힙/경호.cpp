#include <iostream>
#include <vector>

using namespace std;

class priority_queue
{
public:
    priority_queue()
    {
        _data = new int[1];
        _count = 0;
        _capacity = 1;
    }

    ~priority_queue()
    {
        delete[] _data;
    }

private:
    int* _data;
    int _count;
    int _capacity;

    void expand()
    {
        _capacity *= 2;
        int* new_data = new int[_capacity];
        for (int i = 0; i < _count; ++i)
            new_data[i] = _data[i];

        swap(_data, new_data);
        delete[] new_data;
    }

    void add(int value)
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
    void push(int value)
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

    int front() const { return _data[0]; }
    bool empty() const { return _count == 0; }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int input;
    priority_queue pq;
    vector<int> answer;
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

    for (const int& ans : answer)
        cout << ans << "\n";
}
