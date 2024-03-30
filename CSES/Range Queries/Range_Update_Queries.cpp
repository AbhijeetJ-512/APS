#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

int n;
long long fenwick[MAX_N];

void update(int index, long long delta)
{
    for (; index <= n; index += index & -index)
        fenwick[index] += delta;
}

long long query(int index)
{
    long long res = 0;
    for (; index > 0; index -= index & -index)
        res += fenwick[index];
    return res;
}

void range_update(int a, int b, long long u)
{
    update(a, u);
    update(b + 1, -u);
}

int main()
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        range_update(i, i, x);
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b;
            long long u;
            cin >> a >> b >> u;
            range_update(a, b, u);
        }
        else if (type == 2)
        {
            int k;
            cin >> k;
            cout << query(k) << endl;
        }
    }

    return 0;
}
