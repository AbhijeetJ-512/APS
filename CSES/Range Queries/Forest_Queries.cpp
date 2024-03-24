#include <iostream>
using namespace std;

#define MAX_SIZE 1000

void read(int forest[][MAX_SIZE], int dp[][MAX_SIZE + 1], int n)
{
    char x;

    // Read forest data
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            forest[i][j] = (x == '*') ? 1 : 0;
        }
    }
    dp[0][0] = forest[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + forest[i][0];
        dp[0][i] = dp[0][i - 1] + forest[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + forest[i][j];
        }
    }
}
int answer(int dp[][MAX_SIZE + 1], int x1, int y1, int x2, int y2)
{
    return dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
}

int main()
{
    int N, q;
    cin >> N >> q;
    int forest[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE + 1];
    read(forest, dp, N);
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << forest[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int x1, y1, x2, y2;
    for (int i = 0; i < q; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << answer(dp, x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;
    }
    return 0;
}
