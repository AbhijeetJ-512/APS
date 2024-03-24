#include <iostream>
using namespace std;

#define MAX_N 200000

int main()
{
    int n, q;
    cin >> n >> q;

    int arr[MAX_N];
    int prefix_sum[MAX_N];
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
    for (int i = 0; i < q; ++i)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            int k, u;
            cin >> k >> u;
            int diff = u - arr[k];
            arr[k] = u;
            for (int j = k; j <= n; ++j)
                prefix_sum[j] += diff;
        }
        else if (query_type == 2)
        {
            int a, b;
            cin >> a >> b;
            cout << max(0, prefix_sum[b] - prefix_sum[a - 1]) << endl;
        }
    }

    return 0;
}
