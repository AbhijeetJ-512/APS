#include <iostream>
#include <climits>

using namespace std;

int kadane1D(int arr[], int size)
{
    int max_sum = INT_MIN;
    int current_max = 0;
    for (int i = 0; i < size; ++i)
    {
        current_max = max(arr[i], current_max + arr[i]);
        max_sum = max(max_sum, current_max);
    }
    return max_sum;
}
// int kadane1D(int arr[], int size)
// {
//     int t_sum = 0, sum = INT_MIN;
//     for (int i = 0; i < size; i++)
//     {
//         t_sum = t_sum + arr[i];
//         if (t_sum > sum)
//         {
//             sum = t_sum;
//         }
//         if (t_sum < 0)
//         {
//             t_sum = 0;
//         }
//     }
//     return sum;
// }

int kadane2D(int matrix[][5], int rows, int cols)
{
    int max_sum = INT_MIN;

    for (int left = 0; left < cols; ++left)
    {
        int temp[100] = {0};
        for (int right = left; right < cols; ++right)
        {
            for (int i = 0; i < rows; ++i)
            {
                temp[i] += matrix[i][right];
            }

            int max_subarray_sum = kadane1D(temp, rows);
            max_sum = max(max_sum, max_subarray_sum);
        }
    }
    return max_sum;
}

int main()
{
    int matrix[4][5] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}};

    cout << "Maximum sum of subarray: " << kadane2D(matrix, 4, 5) << endl;

    return 0;
}
