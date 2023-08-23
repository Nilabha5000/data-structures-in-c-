#include <iostream>
#include <conio.h>
using namespace std;

class Array{
    int bufferSize;
    int OccupiedPosition;
    int *Container;
    public:
    Array(int n)
    {
        bufferSize = n;
        OccupiedPosition = -1;
        if(bufferSize < 1)
            Container = NULL;
        else
          Container = new int[bufferSize];
    }
    bool IsEmpty()
    {
        return OccupiedPosition == -1;
    }
    bool IsFull()
    {
        return OccupiedPosition == bufferSize-1;
    }
    void Resize(int Size)
    {
        if(Container == NULL && Size > 0){
               bufferSize = Size;
               Container = new int[bufferSize];
               return;
        }
            bufferSize = Size;
            int *newContainer = new int[bufferSize];
             
            if(OccupiedPosition > bufferSize)
            {
                OccupiedPosition = bufferSize-1;
                for(int i = 0; i < OccupiedPosition+1; ++i)
                {
                    newContainer[i] = Container[i];
                }
            }
            else{
                for(int i = 0; i < OccupiedPosition+1; ++i)
                {
                    newContainer[i] = Container[i];
                }

                delete[]Container;

                Container = newContainer;
            }
    }
    int length()
    {
        return (Container == NULL || OccupiedPosition == -1) ? 0 : OccupiedPosition+1;
    }
    int size()
    {
        return bufferSize;
    }
    int AtIndex(int index)
    {
        if(Container==NULL || index > OccupiedPosition || index < 0)
            return -99888872;
        return Container[index];
    }
    bool append(int data)
    {
        if(Container==NULL || OccupiedPosition == bufferSize-1)
           return false;
        Container[++OccupiedPosition] = data;

        return true;
    }
    void edit(int data ,int index)
    {
        if(index > OccupiedPosition || index < 0){
               cout<<"Invalid position \n";
               return;
        }
        Container[index] = data;
    }
    bool insert(int data,int index)
    {
        if(Container==NULL || OccupiedPosition == bufferSize-1)
           return false;
        if(index < 0 || index > OccupiedPosition+1)
        {
            cout<<"Invalid index : ";
            return false;
        }
        int i;
        for(i = OccupiedPosition; i >= index; --i )
        {
            Container[i+1] = Container[i];
        }
        Container[i+1] = data;
        OccupiedPosition++;
        return true;
    }
    void pop(int index){
         if(IsEmpty()){
            cout<<"array underflow !\n";
            return;
         }
         if(index < 0 || index > OccupiedPosition){
              cout<<"invlaid index position !\n";
              return;
         }

         for(int i = index; i < OccupiedPosition; ++i)
         {
              Container[i] = Container[i+1];
         }
         OccupiedPosition--;
    }
    int Search(int data){
        if(Container == NULL || IsEmpty())
             return -1;

        for(int i = 0; i < OccupiedPosition+1; ++i){
              if(data == Container[i])
                   return i;
        }
        return -1;
    }
    ~Array(){
        delete[]Container;
        Container = NULL;
        cout<<"Destructor called !\n";
        OccupiedPosition = -1;
        bufferSize = 0;
    }
};
int main(void)
{
    Array arr(10);
    bool IsStoped = false;
    while(!IsStoped){
       cout<<"1.Insert from a specified position "<<endl;
       cout<<"2.append "<<endl;
       cout<<"3.print all elements of array "<<endl;
       cout<<"4. Search an element "<<endl;
       cout<<"5. delete an element with specified index "<<endl;
       cout<<"6.edit data "<<endl;
       cout<<"7. length and capacity of array "<<endl;
       cout<<"8. Resize the array "<<endl;
       int choice = 0;

       cout<<"Enter your choice : ";
       cin>>choice;
        int data , index,n;
       switch (choice)
       {
       case 1:
           cout<<"Enter data and Index position : ";
           cin>>data>>index;
           if(!arr.insert(data,index)){
               cout<<"array is full\n";
           }
        break;
       case 2:
          cout<<"Enter data for append : ";
          cin>>data;
          if(!arr.append(data))
             cout<<"array is full\n";
             break;
        case 3:
             n = arr.length();
           for(int i = 0; i < n; ++i)
           {
                cout<<arr.AtIndex(i)<<" ";
           }
            break;
        case 4:
          cout<<"Enter data for Search : ";
          cin>>data;
          
          if(arr.Search(data) != -1)
              cout<<"Element found!";
          else
            cout<<"Element not found!";
          break;
        case 5:
          cout<<"Enter index : ";
          cin>>index;
          arr.pop(index);
          break;
        case 6:
            cout<<"Enter data and index : ";
            cin>>data>>index;
           arr.edit(data,index);
           break;
        case 7:
           cout<<"lenght : "<<arr.length()<<" "<<"Capasity : "<<arr.size();
          break;
        case 8:
          int size;
          cout<<"Enter the new size of array : ";
          cin>>size;
          arr.Resize(size);
          break;
       default:
       IsStoped = true;
        break;
       }
       getch();
        system("cls");
    }

    cout<<"\n---------------\n";    
    return 0;
}