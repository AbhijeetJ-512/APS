#include <iostream>
#include <cstring>

using namespace std;

// Function to return the maximum of two integers
int max(int x, int y)
{
    return (x > y) ? x : y;
}

// Function to solve the book shop problem using dynamic programming
int book_shop(int *price, int *pages, int n, int Cost)
{
    // Initializing an array to store the maximum number of pages that can be bought for each cost
    int dp[Cost + 1];

    // Initialize dp array with -1 using memset
    memset(dp, -1, sizeof(dp));

    // Base case: If the cost is 0, then no books can be bought, so the maximum pages that can be bought is 0
    dp[0] = 0;

    // Loop through each book
    for (int i = 0; i < n; i++)
    {
        // Iterate through each possible cost starting from the current book's price
        for (int j = Cost - price[i]; j >= 0; j--)
        {
            // If the current cost j is achievable (i.e., dp[j] is not -1), update dp[j + price[i]] to store the maximum pages
            // that can be bought considering the current book
            if (dp[j] != -1)
            {
                dp[j + price[i]] = max(dp[j + price[i]], dp[j] + pages[i]);
            }
        }
    }

    // After processing all books, update dp array to store the maximum pages that can be bought for each cost
    for (int i = 1; i <= Cost; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
    }

    // Return the maximum pages that can be bought with the given cost
    return dp[Cost];
}

int main()
{
    int n, Cost;
    // Input the number of books and the total cost
    cin >> n >> Cost;

    // Array to store the prices of the books
    int price[n];
    cout << "Enter prices\n";
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    // Array to store the number of pages in each book
    int pages[n];
    cout << "Enter no of pages\n";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    cout << book_shop(price, pages, n, Cost);
}
