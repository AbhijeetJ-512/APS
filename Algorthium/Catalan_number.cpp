#include <iostream>

using namespace std;

unsigned long long catalan(int n)
{
    unsigned long long catalan_nums[n + 1];
    catalan_nums[0] = catalan_nums[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        catalan_nums[i] = 0;
        for (int j = 0; j < i; ++j)
        {
            catalan_nums[i] += catalan_nums[j] * catalan_nums[i - j - 1];
        }
    }

    return catalan_nums[n];
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Catalan number for " << n << " is " << catalan(n) << endl;
    return 0;
}
