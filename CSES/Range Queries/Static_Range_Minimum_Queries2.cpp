#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int min(int a, int b)
{
    return (a < b) ? a : b;
}
void build_tree(int arr[], int tree[], int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = start + (end - start) / 2;
        build_tree(arr, tree, 2 * node, start, mid);
        build_tree(arr, tree, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int tree[], int node, int start, int end, int left, int right)
{
    if (right < start || left > end)
    {
        return INT_MAX;
    }
    if (left <= start && right >= end)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return min(query(tree, 2 * node, start, mid, left, right),
               query(tree, 2 * node + 1, mid + 1, end, left, right));
}

void update(int tree[], int node, int start, int end, int idx, int value)
{
    if (start == end)
    {
        tree[node] = value;
    }
    else
    {
        int mid = (start + end) / 2;
        if (idx <= mid)
        {
            update(tree, 2 * node, start, mid, idx, value);
        }
        else
        {
            update(tree, 2 * node + 1, mid + 1, end, idx, value);
        }
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tree[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        tree[i] = INT_MAX;
    }

    build_tree(arr, tree, 1, 0, n - 1);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << query(tree, 1, 0, n - 1, a - 1, b - 1) << endl;
    }

    return 0;
}