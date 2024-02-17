#include <iostream>

void mergesort(int *,int ,int);

void merge(int*,int,int);
int main()
{
    int *arr = NULL;
    int n = 0;
  
    std::cin>>n;
    
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }
    
    mergesort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    
    return 0;
}

void mergesort(int *arr, int l , int r)
{

    if(r <= l)
       return;
    int mid = (l+r)/2;

    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    
    merge(arr,l,r);
    
}

void merge(int *arr , int l , int r){
    
    int mid = 0;
    int *arr1 = NULL , *arr2 = NULL;
    
    mid = (l+r)/2;
    arr1 = new int[(mid - l)+1];
    arr2 = new int[(r - (mid+1))+1];

    for(int i = 0; i < (mid - l)+1; ++i)
        arr1[i] = arr[i];
    for(int i = 0, j = mid+1; i < (r-(mid+1))+1 && j <= r; ++i,++j)
    {
          arr2[i] = arr[j];
    }

    int i = 0 , j = 0;

    int n = (mid-l)+1 , m = (r - (mid+1))+1;

    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j]){
           arr[l++] = arr1[i];
           i++;
        }
        else
           arr[l++] = arr2[j++];
    }

    while(i < n)
      arr[l++] = arr1[i++];
    
    while(j < m)
      arr[l++] = arr2[j++];

    delete [] arr1;
    delete [] arr2;
}