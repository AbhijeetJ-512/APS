#include <iostream>
#include <climits>
using namespace std;
int kadnaes(int *arr, int n)
{
    int t_sum = 0, sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        t_sum = t_sum + arr[i];
        if (t_sum > sum)
        {
            sum = t_sum;
        }
        if (t_sum < 0)
        {
            t_sum = 0;
        }
    }
    return sum;
}
int main()
{
    int arr[] = {5, 6, -4, 5, -7};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << kadnaes(arr, n);
}