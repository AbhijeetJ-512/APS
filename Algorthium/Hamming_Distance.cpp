// This code explains how many bits should be modified to change one number to another.
#include <iostream>
using namespace std;
int get_count(int a, int b)
{
    int n = a ^ b;
    int count = 0;
    while (n > 0)
    {
        count++;
        n &= n - 1;
    }
    return count;
}
int main()
{
    int a, b;
    printf("Enter 2 numbers(a and b):");
    scanf("%d%d", &a, &b);
    printf("Answer:%d", get_count(a, b));
}