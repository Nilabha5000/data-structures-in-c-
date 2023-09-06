#include <iostream>
#include <string>
using namespace std;
struct node{
    int info;
    node *next;
};

class stack{
      node *top;
      int preceed(char);
      public:
      stack();
      void push(int);
      void pop();
      node *peek();
      string toPostfix(string);
      int EvalPostfix(string);
      bool isPalindrome(int);
      ~stack();
};

int stack::preceed(char c)
{
    if(c == '(')
        return 1;
    if(c == '+' || c == '-')
         return 2;
    if(c == '*' || c == '/' || c == '%')
        return 3;
    if(c == '^')
       return 4;
    return -1;
}
stack::~stack()
{
    if(top)
    {
        node *prev = NULL;
        while(top)
        {
            prev = top;
            top = top->next;
            delete prev;
        }
    }
}
stack::stack()
{
    top = NULL;
}
void stack::push(int data)
{
    node *newnode = new node;
    newnode->info = data;
    newnode->next = top;
    top = newnode;
}
void stack::pop()
{
    if(top != NULL){ 
       node *delnode = top;
       top = top->next;
       delete delnode;
    }
}
node* stack::peek()
{
    return top;
}

bool stack::isPalindrome(int num){
    int t1 = num;
    int t2 = num;
    stack s;
    while(t1)
    {
        s.push(t1%10);
        t1 = t1/10;
    }

    while(s.peek())
    {
        if(t2%10 != s.peek()->info)
            return false;
        t2 /= 10;
        s.pop();
    }
    return true;
}

string stack::toPostfix(string infix)
{
    string postfix = "";
    stack s;
    bool oprand , op;
    s.push('(');
    infix += ')';
    int i = 0;
    while(s.peek())
    {
       oprand = ((infix[i] >= 'a' && infix[i] <= 'z')  || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'));
       op = (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^');

       if(oprand)
           postfix += infix[i];
        else if(infix[i] == '(')
            s.push('(');
       else if(op)
       {
           if(s.preceed((char)s.peek()->info) < s.preceed((char)infix[i]))
           {
                s.push(infix[i]);    
           }
           else{
                 while(s.preceed((char)s.peek()->info) >= s.preceed((char)infix[i]))
                 {
                     postfix += (char)s.peek()->info;
                     s.pop();
                 }
                 s.push(infix[i]);
           }
       }
       else if(infix[i] == ')')
       {
           while(s.peek()->info != '(')
           {
                postfix += (char)s.peek()->info;
                s.pop();
           }
           s.pop();
       }
       

       if(i < infix.length())
           i++;
    }
    return postfix;
}
int stack::EvalPostfix(string postfix){
    stack s1;
    int op1 , op2;
    int res;
    for(auto i : postfix)
    {
        if(i>= '0' && i <= '9')
            s1.push(i);
        else if(i == '+' || i == '-' || i == '*' || i == '/')
        {
            op2 = s1.peek()->info - 48;
            s1.pop();
            op1 = s1.peek()->info - 48;
            s1.pop();

            switch (i)
            {
            case '+':
               res = op1 + op2;
               s1.push(res+48);
                break;
            case '-':
               res = op1 - op2;
               s1.push(res+48);
               break;
            case '*':
               res = op1 * op2;
            s1.push(res+48);
               break;
            case '/':
              res = op1/op2;
              s1.push(res+48);
               break;
            default:
                break;
            }
        }
    }
    return s1.peek()->info - 48;
}
int main()
{
    stack s;
    string postfix = s.toPostfix("3+5*(7/5)");
    cout<<s.EvalPostfix(postfix);
    return 0;
}