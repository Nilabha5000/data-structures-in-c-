#include <iostream>
using namespace std;

class DynArray{
    private :
     int Capacity;
     int LastIndex;
     int *arr;
    void doubleArray()
    {
        Capacity *= 2;
        int *newArr = new int[Capacity];

        for(int i = 0; i <= LastIndex; ++i)
        {
            newArr[i] = arr[i];
        }

        delete []arr;
        arr = newArr;
    }
    void halfArray(){
        Capacity /= 2;
        int *newArr = new int[Capacity];
        for (int i = 0; i <= LastIndex; i++)
        {
            newArr[i] = arr[i];        
        }
        delete [] arr;
        arr = newArr;
    }
    public:
    DynArray(int size)
    {
        if(size > 0)
        {
            Capacity = size;
            LastIndex = -1;
            arr = new int[Capacity];
        }
        else
        arr = NULL;
    }
   
    int CurrentCapacity()
    {
        return Capacity;
    }
    int length()
    {
        return LastIndex+1;
    }
    bool IsEmpty(){
        return LastIndex == -1;
    }
    bool IsFull(){
        return LastIndex == Capacity-1;
    }

    void append(int data)
    {
        if(IsFull())
            doubleArray();
        arr[++LastIndex] = data;
    }

    void insert(int data,int index)
    {
        if(index < 0 || index > LastIndex+1)
        {
            cout<<"Invalid index : ";
            return;
        }
        if(IsFull())
            doubleArray();
        for(int i = LastIndex; i >= index; --i )
        {
            arr[i+1] = arr[i];
        }
        arr[index] = data;
        LastIndex++;
    }

     void pop(int index){
         if(IsEmpty()){
            cout<<"array underflow !\n";
            return;
         }
         if(index < 0 || index > LastIndex){
              cout<<"invlaid index position !\n";
              return;
         }

         for(int i = index; i < LastIndex; ++i)
         {
              arr[i] = arr[i+1];
         }
         LastIndex--;
         
         //checking if the array is half 
         if(Capacity > 1 && (LastIndex+1) <= (Capacity/2))
            halfArray();
    }
    void edit(int data ,int index)
    {
        if(index > LastIndex || index < 0){
               cout<<"Invalid index \n";
               return;
        }
        arr[index] = data;
    }
    
    int search(int data)
    {
        int n = length();
        for(int i = 0; i < n; ++i)
        {
            if(data == arr[i])
                return i;
        }
        return -1;
    }

    int AtIndex(int index)
    {
        if(index > LastIndex || index < 0){
               cout<<"Invalid position \n";
               return 88808288;
        }
        return arr[index];
    }
    
    ~DynArray()
    {
        delete [] arr;
        arr = NULL;
    }
};
int main()
{
    DynArray a(5);
    cout<<"array initial capacity :"<<a.CurrentCapacity()<<endl;
    a.append(56);
    a.append(78);
    a.insert(67,1);
    a.append(100);
    a.append(77);
    a.append(108);
    a.append(78);


    for(int i = 0; i < a.length(); ++i)
        cout<<a.AtIndex(i)<<" ";

    a.append(17);
    cout<<"\n array capacity :"<<a.CurrentCapacity()<<endl;
    a.insert(100,0);
    a.insert(199,2);
    a.append(15);
    a.append(9008);

    cout<<"\n array capacity :"<<a.CurrentCapacity();
    cout<<"\n\n";
    for(int i = 0; i < a.length(); ++i)
        cout<<a.AtIndex(i)<<" ";
    
    a.pop(0);
    a.pop(2);

    cout<<"\n array capacity :"<<a.CurrentCapacity();
    cout<<"\n\n";
    for(int i = 0; i < a.length(); ++i)
        cout<<a.AtIndex(i)<<" ";
    return 0;
}
