#include<iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    long long int prefixSum[n];
    for (int i = 1; i <= n; ++i) 
    {
        int x;
        cin >> x;
        prefixSum[i] = prefixSum[i - 1] + x;
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        long long sum = prefixSum[b] - prefixSum[a - 1];
        cout << sum << endl;
    }
    return 0;
}