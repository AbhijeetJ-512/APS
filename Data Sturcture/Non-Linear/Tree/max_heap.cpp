#include <iostream>
#include <stdbool.h>
using namespace std;

void max_heap(int *H, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        int k = i;
        int v = H[i];
        bool heap = false;
        while (!heap && 2 * k <= n)
        {
            int j = 2 * k;
            if (j < n)
            {
                if (H[j + 1] > H[j])
                {
                    j++;
                }
            }
            if (v >= H[j])
            {
                heap = true;
            }
            else
            {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    max_heap(arr, n);
    for (int i = 1; i < n + 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nThe largest value is:%d\n", arr[1]);
}
