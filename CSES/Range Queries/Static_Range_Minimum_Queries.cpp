#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 2e5 + 5;
const int K = 20;

int st[MAX_N][K + 1];

int main()
{
    int n, q;
    cin >> n >> q;

    int arr[MAX_N];

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        st[i][0] = arr[i];
    }

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        int k = log2(b - a + 1);
        cout << min(st[a][k], st[b - (1 << k) + 1][k]) << endl;
    }

    return 0;
}
