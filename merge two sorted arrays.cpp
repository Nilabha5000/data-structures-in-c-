#include <iostream>
#include <algorithm>

int *merge(int *,int*, int , int);

//driver code
int main()
{
    int n , m;
    int *arr1 = NULL, *arr2 = NULL;
    int *arr3 = NULL;
    std::cin>>n;
    arr1 = new int[n];

    for(int i = 0; i < n; ++i)
        std::cin>>arr1[i];

    std::cin>>m;
    arr2 = new int[m];

    for(int i = 0; i < m; ++i)
        std::cin>>arr2[i];
    
    std::sort(arr1,arr1+n);
    std::sort(arr2,arr2+m);
   
    arr3 = merge(arr1,arr2,n,m);
   
   for(int i = 0; i < (n+m); ++i)
        std::cout<<arr3[i]<<" ";
    std::cout<<"\n";

   delete [] arr1;
   delete [] arr2;
   delete [] arr3;
    return 0;
}

int *merge(int *arr1 , int *arr2 , int n , int m)
{
    int i = 0 , j = 0;
    int Li = -1;
    int *ans = new int[(n+m)];
    
    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            ans[++Li] = arr1[i];
            i++;
        }

        else{

            ans[++Li] = arr2[j];
            j++;
        }
    }


    while(i < n)
    {
        ans[++Li] = arr1[i];
        i++;
    }

    while(j < m)
    {
        ans[++Li] = arr2[j];
        j++;
    }
      
    return ans;

}