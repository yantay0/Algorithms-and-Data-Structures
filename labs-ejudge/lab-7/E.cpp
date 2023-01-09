#include <iostream>
#include <vector>
using namespace std;

struct Row
{
    int sum;
    vector<int> items;
    Row()
    {
        this->sum = 0;
    }
    void append(int x)
    {
        this->sum += x;
        this->items.push_back(x);
    }
    void print()
    {
        for (int i = 0; i < this->items.size(); ++i)
        {
            cout << this->items[i] << " ";
        }
        cout << endl;
    }
    bool greater(Row *other)
    {
        if (this->sum > other->sum)
            return true;
        if (this->sum == other->sum)
        {
            for (int i = 0; i < this->items.size(); ++i)
            {
                if (this->items[i] != other->items[i])
                {
                    return this->items[i] < other->items[i];
                }
            }
            return false;
        }
        return false;
    }
};
void merge(Row *a, int l1, int r1, int l2, int r2)
{
    int n1 = r1 - l1 + 1;
    Row L[n1];
    for (int i = 0; i < n1; ++i)
    {
        L[i] = a[l1 + i];
    }
    int n2 = r2 - l2 + 1;
    Row R[n2];
    for (int i = 0; i < n2; ++i)
    {
        R[i] = a[l2 + i];
    }
    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        if (L[i1].greater(&R[i2]))
        {
            a[i++] = L[i1++];
        }
        else
        {
            a[i++] = R[i2++];
        }
    }

    while (i1 < n1)
    {
        a[i++] = L[i1++];
    }

    while (i2 < n2)
    {
        a[i++] = R[i2++];
    }
}

void mergeSort(Row *a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, m + 1, r);
    }
}
int main()
{
    int n, m, x;
    cin >> n >> m;
    Row Rows[n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            Rows[i].append(x);
        }
    }
    mergeSort(Rows, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        Rows[i].print();
    }

    return 0;
}