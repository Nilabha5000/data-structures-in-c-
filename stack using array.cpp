#include <iostream>
using namespace std;

class stack 
{
private:
     int top;
     int capacity;
     int min;
     int *s;
public:
    stack(int);
    stack(stack&);
    void push(int);
    bool isfull();
    int getMinimum();
    bool isempty();
    int* peek();
    void pop();
    ~stack();
};

stack::stack(int size)
{
    if(size > 0){
        top = -1;
        capacity = size;
        s = new int[capacity];
    }
    else
       s = NULL;
}

stack::stack(stack&s1)
{
    s1.top = top;
    s1.capacity = capacity;
    s1.s = new int[capacity];
    for(int i = 0; i <= s1.top; ++i)
         s1.s[i] = s[i];
}
void stack::push(int data)
{
    if(isempty()){
          s[++top] = data;
          min = data;
    }
    else if(!isfull())
    {
        s[++top] = data;
        if(s[top] < min)
            min = data;
    }   
    
}
int stack::getMinimum()
{
    try
    {
        if(isempty())
           throw -1;
        return min;
    }
    catch(int e)
    {
        cerr<<"ERROR\n";
    }
}
stack::~stack()
{
    if(s)
      delete[]s;
    cout<<"\n";
}
int* stack::peek()
{
    if(!isempty())
       return (s+top);
    return NULL;
}
void stack::pop()
{
    if(!isempty())
    {
        if(min == s[top]){
           top--;
           min = s[top];
           for(int i = top; i > -1; --i)
           {
              if(s[i] <= min)
                min = s[i];
           }
        }
        else
          top--;
    }
}
bool stack::isempty()
{
    return (top == -1);
}
bool stack::isfull(){
    return (top == capacity-1);
}
int main()
{
    stack s1(10); 
    
   s1.push(7);
    s1.push(8);
    s1.push(9);
    
    s1.push(10);
    s1.push(6);
    s1.push(1);
    s1.push(88);
    s1.push(4);
    s1.push(100);
    s1.push(77);
    s1.push(13);
    s1.push(67);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    
    if(s1.peek())
       cout<<*s1.peek()<<" at the top\n";
    cout<<"minimum element in stack is "<<s1.getMinimum();
    cout<<"\n";
    return 0;
}