#include <iostream>
using namespace std;

#define MAX_N 200000

int main()
{
    int n, q;
    cin >> n >> q;

    int arr[MAX_N];
    int prefix_xor[MAX_N];
    prefix_xor[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        prefix_xor[i + 1] = prefix_xor[i] ^ arr[i];
    }
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        int xor_sum = prefix_xor[b] ^ prefix_xor[a - 1];
        cout << xor_sum << endl;
    }

    return 0;
}
