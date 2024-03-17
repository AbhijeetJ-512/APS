#include<iostream>
using namespace std;
int main()
{
    char ssss[1000001];
    int max=0,count=0,i=0;
    cin>>ssss;
    char letter = ssss[0];
    while (ssss[i]!='\0')
    {
        if(letter==ssss[i])
        {
            count++;
        }
        else
        {
            count=1;
            letter=ssss[i];
        }
        max = (max<count) ? count:max;
        i++;
    }
    if(max==0)
    {
        cout<<count;
    }
    else
    {
    cout<<max;
    
}}