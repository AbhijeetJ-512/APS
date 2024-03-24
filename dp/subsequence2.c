/* Longest common subsequence
ex  s1-akdef
    s2- kfgce
    answer  = akfgcdef-> */
#include<stdio.h>
#include<math.h>
#include<string.h>
int max(int n1,int n2)
{
    return n1<n2 ? n1:n2;
}
int solution(char str1[10],char str2[10])
{
    int l1 = strlen(str1),l2 = strlen(str2);
    int dp[l1+1][l2+1];
    for(int i=0; i<=l1; i++)
    {
        dp[i][0]=i;
    }
    for(int i=0; i<=l2; i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    
    return dp[l1][l2];
}
int main()
{
    char string1[10];
    char string2[10];
    scanf("%s",string1);
    scanf("%s",string2);
    int ans = solution(string1,string2);
    printf("Longest common subsequence is %d\n",ans);
    return 0;
}