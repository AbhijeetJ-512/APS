#include<iostream>
using namespace std;
void merge(long long int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    long int L[n1], R[n2];

    for (long int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (long int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(long long int *arr,int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-2);
    for(long long int i=1;i<=n;i++)
    {
        if(i!=arr[i-1])
        {
            cout<<i;
            exit(0);
        }
    }
    return 0;
}