#include <iostream>

void mergesort(int *,int);

void merge(int*,int*,int*,int ,int);
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
    
    mergesort(arr,n);

    for (int i = 0; i < n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    
    return 0;
}

void mergesort(int *arr, int n)
{

    if(n == 1)
       return;
    int mid =  (n-1)/2;
    int n1 = mid+1 , n2 = n - (mid+1);
    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[i];
    }

    for(int i = 0 , j = mid+1; i < n2 && j < n; ++i,++j){
           arr2[i] = arr[j];
    }
     
    mergesort(arr1,(mid+1));
    mergesort(arr2,n-(mid+1));
    
    merge(arr1,arr2,arr,mid+1,(n-(mid+1)));

    delete [] arr1;
    delete [] arr2;
    
}

void merge(int *arr1 , int *arr2 ,int *arr3 ,int n1 ,int n2)
{
    int i = 0 , j = 0;
    int Li = -1;
    
    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
        {
           arr3[++Li] = arr1[i];
            i++;
        }

        else{

            arr3[++Li] = arr2[j];
            j++;
        }
    }


    while(i < n1)
    {
        arr3[++Li] = arr1[i];
        i++;
    }

    while(j < n2)
    {
        arr3[++Li] = arr2[j];
        j++;
    }
      
}
