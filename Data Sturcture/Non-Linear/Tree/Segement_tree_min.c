#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    int arr[] = {3, 2, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int tree[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        tree[i] = INT_MAX;
    }
    build_tree(arr, tree, 1, 0, n - 1);
    for (int i = 0; i < 2 * n; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("\nMinimum in range [1, 3]: %d\n", query(tree, 1, 0, n - 1, 1, 3));

    // Update value at index 2 to 5
    update(tree, 1, 0, n - 1, 2, 5);

    printf("Minimum in range [1, 3] after update: %d\n", query(tree, 1, 0, n - 1, 1, 3));

    return 0;
}