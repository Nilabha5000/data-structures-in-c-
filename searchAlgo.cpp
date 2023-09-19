#include <iostream>

int linear_search(int arr[],int x, int n)
{
    for(int i = 0; i < n; i++)
    {
       if (x == arr[i])
          return i;
    }
    return -1;
}

int binary_search(int arr[],int x, int n)
{
     int mid , l , r;
     l = 0;
     r = n-1;
    while (l<=r)
    {
        mid = (l+r)/2;
        if(x == arr[mid])
           return mid;
        else if(x > arr[mid])
            l = mid+1;
        else
         r = mid -1;
    }
    return -1;
    
}
int main()
{
    
    return 0;
}