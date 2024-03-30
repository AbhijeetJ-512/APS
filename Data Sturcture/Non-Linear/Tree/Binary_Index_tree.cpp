#include <iostream>

using namespace std;

void update(int fenwick_tree[], int n, int index, int value)
{
    while (index <= n)
    {
        fenwick_tree[index] += value;
        index += index & -index;
    }
}

int query(int fenwick_tree[], int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += fenwick_tree[index];
        index -= index & -index;
    }
    return sum;
}

int main()
{
    int arr[] = {2, 1, 3, 4, 2, 3, 1, 6, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int fenwick_tree[n + 1];
    for (int i = 1; i <= n; i++)
    {
        fenwick_tree[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        update(fenwick_tree, n, i, arr[i - 1]);
    }

    cout << "Fenwick Tree: ";
    for (int i = 1; i <= n; i++)
    {
        cout << fenwick_tree[i] << " ";
    }
    cout << endl;
    cout << "Query result from index 1 to 6: " << query(fenwick_tree, 6) - query(fenwick_tree, 0) << endl;
    cout << "Query result from index 2 to 9: " << query(fenwick_tree, 9) - query(fenwick_tree, 1) << endl;

    return 0;
}
