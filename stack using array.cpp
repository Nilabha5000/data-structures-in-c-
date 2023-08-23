#include <iostream>
using namespace std;

class stack 
{
private:
     int top;
     int capacity;
     int *s;
public:
    stack(int);
    stack(stack&);
    void push(int);
    bool isfull();
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
    if(s && top != capacity-1)
        s[++top] = data;
}
stack::~stack()
{
    if(s)
      delete[]s;
    cout<<"\n";
}
int* stack::peek()
{
    if(top != -1)
       return (s+top);
    return NULL;
}
void stack::pop()
{
    if(top != -1)
       top--;
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
    s1.push(10);
    s1.push(9);
    s1.push(8);
    
    s1.push(7);
    s1.push(6);
    cout<<*s1.peek();
    cout<<"\n";
    return 0;
}
