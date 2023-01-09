#include <iostream>
#include <algorithm>
using namespace std;

struct hp
{
private:
    int *arr;
    int capacity;
    int length;

    void heap_up(int i)
    {
        if (i > 0)
        {
            int p_pos = (i - 1) / 2;
            if (arr[i] < arr[p_pos])
            {
                swap(arr[i], arr[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min_pos = i;
        if (l < length and arr[l] < arr[min_pos])
            min_pos = l;
        if (r < length and arr[r] < arr[min_pos])
            min_pos = r;
        if (min_pos != i)
        {
            swap(arr[min_pos], arr[i]);
            heap_down(min_pos);
        }
    }

    void _cut_min()
    {
        arr[0] = arr[length - 1];
        length = max(length - 1, 0);
        heap_down(0);
    }

    void _add(int x)
    {
        arr[length] = x;
        length++;
        heap_up(length - 1);
    }
    void _cut_max()
    {
        if (arr[0] - 1 > 0)
        {
            arr[0] = arr[0] - 1;
        }
        else
        {
            arr[0] = arr[length - 1];
            length = max(length - 1, 0);
        }
        heap_down(0);
    }

public:
    hp(int capacity)
    {
        arr = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }

    int cut_max()
    {
        int res = arr[0];
        _cut_max();
        return res;
    }

       void insert(int val, int k)
    {
        if (length < k)
            _add(val);
        else if (length == k and arr[0] < val)
        {
            arr[0] = val;
            heap_down(0);
        }
    }

    long long print(int k)
    {
        long long sum = 0;
        if (length < k)
            k = length;
        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
};

int main()
{

    hp h(200002);
    int n, k;
    cin >> n >> k;

    while (n--)
    {
        string s;
        int val;
        cin >> s;
        if (s == "print")
            cout << h.print(k) << endl;
        else if (s == "insert")
        {
            cin >> val;
            h.insert(val, k);
        }
    }

    return 0;
}