#include <iostream>

using namespace std;

void update(long long int fenwick_tree[], long int n, long int index, long long int value)
{
    while (index <= n)
    {
        fenwick_tree[index] += value;
        index += index & -index;
    }
}

long long int query(long long int fenwick_tree[], long int index)
{
    long long int sum = 0;
    while (index > 0)
    {
        sum += fenwick_tree[index];
        index -= index & -index;
    }
    return sum;
}

int main()
{
    long int n, q;
    cin >> n >> q;
    long long int arr[n];
    long long int fenwick_tree[n + 1];

    for (long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (long int i = 1; i <= n; i++)
    {
        fenwick_tree[i] = 0;
    }
    for (long int i = 0; i < n; i++)
    {
        update(fenwick_tree, n, i + 1, arr[i]);
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            long int k;
            long long int u;
            cin >> k >> u;
            update(fenwick_tree, n, k, u - arr[k - 1]);
            arr[k - 1] = u;
        }
        else if (type == 2)
        {
            long int a, b;
            cin >> a >> b;
            cout << query(fenwick_tree, b) - query(fenwick_tree, a - 1) << endl;
        }
    }
    return 0;
}
