#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int p[n];
    long long int min_diff = __INT32_MAX__;
    for(long long int i=0;i<n;i++)
    {
        cin>>p[i];
    }

    for(long long  int mask=0;mask<(1<<n);mask++)
    {
        long long int sum1=0,sum2=0;
        for(long long int i=0;i<n;i++)
        {
            if(mask & (1<<i))
            {
                sum1 += p[i];
            }
            else
            {
                sum2 +=p[i];
            }
        }
        min_diff = min(min_diff,abs(sum1-sum2));
    }
    cout<< min_diff;
}