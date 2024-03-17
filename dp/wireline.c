#include<stdio.h>
#include<math.h>
#include<limits.h>

int min(int x,int y)
{
    return (x<y) ? x:y;
}

int count_bits(int n)
{
    int count =0;
    while(n!=0)
    {
        count = ((n&1) == 1) ? count+1:count;
        n=n>>1;
    }
    return count;
}

int assign(int n,int matrix[3][3])
{
    int dp[8];
    for(int i=0;i<pow(2,n);i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(int mask=0;mask<pow(2,n);mask++)
    {
        int x=count_bits(mask);
        for(int j=0;j<3;j++)
        {
            if((mask & (1 << j)) == 0)
            {
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)],(dp[mask]+matrix[x][j]));
            }
        }
    }
    int index  = pow(2,n)-1;
    return dp[index];
}
int main()
{
    int matrix[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int ans = assign(3,matrix);
    printf("%d\n",ans);
}