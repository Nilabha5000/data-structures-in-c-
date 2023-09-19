#include <iostream>

class Heap
{
private:
    int heapSize;
    int *heaparr;
    int ArrSize;
    void HalfArr();
    void DoubleArr();
public:
    Heap();
    void insert(int);
    void Delete();
    bool IsEmpty();
    int getMax();
    void PrintHeap();
    void sort(int *,int);
    ~Heap();
};

void Heap::DoubleArr()
{
     int *arr = new int[ArrSize*2];

     for(int i = 0; i < ArrSize; ++i)
         arr[i] = heaparr[i];
    delete [] heaparr;
    heaparr = arr;
    ArrSize *= 2;
}
void Heap::HalfArr()
{
    int *arr = new int[ArrSize/2];
    for (int i = 0; i < heapSize; i++)
    {
        arr[i] = heaparr[i];
    }
    delete [] heaparr;
    heaparr = arr;
    ArrSize /= 2;
}

bool Heap::IsEmpty(){
    return heapSize == 0;
}
void Heap::insert(int x)
{
    if(heapSize >= ArrSize)
       DoubleArr();
    else if(IsEmpty()){
        heaparr[heapSize++] = x;
        return;
    }

    int temp = x;
    int parentNode = (heapSize-1)/2;
    int childNode = heapSize;
    while(childNode > 0 && temp >= heaparr[parentNode]){
        heaparr[childNode] = heaparr[parentNode];
        childNode = parentNode;
        parentNode = (childNode-1)/2;
    }
      heaparr[childNode] = temp;
      heapSize++; 
}
void Heap::Delete()
{
    if(IsEmpty())
       return;
    if(heapSize == 1)
    {
         heapSize--;
         return;
    }
    int parentNode = 0;
    int childNode;
    int temp = heaparr[heapSize-1];
    heapSize--;
    while((2*parentNode+1) < heapSize)
    {
        if(2*parentNode+2 < heapSize && (temp > heaparr[2*parentNode+1] && temp > heaparr[2*parentNode+2])){
            
            break;
        }
        else if(2*parentNode+2 > heapSize || heaparr[2*parentNode+1] > heaparr[2*parentNode+2])
        {
            childNode = 2*parentNode+1;
            heaparr[parentNode] = heaparr[childNode];
            parentNode = childNode;
        }
        else{
           childNode = 2*parentNode+2;
            heaparr[parentNode] = heaparr[childNode];
            parentNode = childNode;

        }
    }
    heaparr[parentNode] = temp;

    if(ArrSize > 1 && heapSize <= ArrSize/2)
       HalfArr();
   
}
void Heap::PrintHeap()
{
    for (int i = 0; i < heapSize; i++)
    {
        std::cout<<heaparr[i]<<" ";
    }
    
}
int Heap::getMax()
{
    if(IsEmpty())
       throw 1;
     return heaparr[0];
}
Heap::Heap()
{
    ArrSize = 5;
    heaparr = new int[ArrSize];
    heapSize = 0;
}
void Heap::sort(int *arr,int n)
{
    Heap h;
    for(int i = 0; i < n; ++i)
        h.insert(arr[i]);
    for(int i = n-1; i >= 0; --i)
    {
        arr[i] = h.getMax();
        h.Delete();
    }
    
}
Heap::~Heap()
{
    delete [] heaparr;
}

int main()
{
    Heap h;
    int arr[10] = {10,3,7,9,2,4,1,5,6,8};
    for(int i = 0; i < 10; ++i)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    h.sort(arr,10);
    for(int i = 0; i < 10; ++i)
    {
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\nEnd";
    return 0;
}
