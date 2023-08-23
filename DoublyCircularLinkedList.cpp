#include <iostream>

using namespace std;

struct node{
      int info;
      node *next , *prev;
};

class CDLL{
    node *start;
    public:
    CDLL();
    ~CDLL();
    void push_back(int);
    void printCDLL(char);
    void push_after(int , int);
    node*search(int);
    void push_front(int);
    void pop_back();
    void pop(int);
    void pop_front();
};
CDLL::CDLL()
{
    start = NULL;
}

CDLL::~CDLL()
{
    cout<<"Dystructor called !\n";
    if(start != NULL)
    {
      node *last = start->prev;
      while(start != last)
      {
        start = start->next;
        delete start->prev;
      }
      delete last;
   }
}
void CDLL::push_back(int data)
{
    if(start == NULL)
    {
        start = new node;
        start->info = data;
        start->next = start;
        start->prev = start;
        return;
    }

    node *newnode = new node;

    newnode->info = data;
    newnode->next = start;
    newnode->prev = start->prev;
    start->prev->next = newnode;
    start->prev = newnode;
}
void CDLL::printCDLL(char direction = 'l')
{
    if(start == NULL)
    {
       cout<<"List is empty !\n";
    }
    else
    {
        if(direction == 'l')
        {
            node *s = start;
            node *last = s->prev;

            while (s != last)
            {
                cout<<s->info<<" ";
                s = s->next;
            }
            cout<<s->info<<" ";
        }
        else if(direction == 'r')
        {
            node *last = start->prev; 

            while (last != start)
            {
                cout<<last->info<<" ";
                last = last->prev;
            }
            cout<<last->info<<" ";
        }
    }
    cout<<endl;
}
void CDLL::push_front(int data)
{
    node *newnode = NULL;
    newnode = new node;
    newnode->info = data;
    if(start == NULL)
    {
        start = newnode;
        start->next = start;
        start->prev = start;
        return;
    }
    newnode->next = start;
    newnode->prev = start->prev;
    start->prev->next = newnode;
    start->prev = newnode;
    start = newnode;
}

node*CDLL::search(int data)
{
    if(start != NULL)
    {
        node*s = start;
        node*l = start->prev;
        while(s != l)
        {
             if(s->info == data)
                 return s;
            s = s->next;
        }
        if(l->info == data)
            return l;
    }
    return NULL;
}

void CDLL::push_after(int dest , int data)
{
    node *destNode = search(dest);

    if(destNode != NULL)
    {
        node *newnode = new node;
        newnode->info = data;
        newnode->next = destNode->next;
        newnode->prev = destNode;
        newnode->next->prev = newnode;
        destNode->next = newnode;
    }
}
void CDLL::pop_front()
{
    if(start != NULL)
    {
        node *p = start->next;
        if(p == start)
        {
            delete p;
            start = NULL;
        }
        else{
            p->prev = start->prev;
            start->prev->next = p;
            delete start;
            start = p;
        }
    }
}

void CDLL::pop(int data)
{
    if(start)
    {
        node *last = start->prev;
        node *s = search(data);

        if(s != NULL && s == start)
           pop_front();
        else if(s != NULL && s == last)
           pop_back();
        else{
            if(s)
            {
                s->prev->next = s->next;
                s->next->prev = s->prev;
                delete s;
            }
        }
    }
}
void CDLL::pop_back()
{
    if(start != NULL){
       node *p = start->prev;
       
       if(p == start)
       {
           delete start;
           start = NULL;
       }
       else
       {
           start->prev = p->prev;
           start->prev->next = start;
           delete p;
       }
       
    }
}
int main()
{
    CDLL list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_front(20);
    list.push_front(77);
    list.push_front(9);
    list.push_after(3,8);
    list.push_after(5,112);
    list.pop_front();
    list.pop_back();
    list.pop(2);
    list.pop(77);
    list.pop(5);
    list.printCDLL();
    list.printCDLL('r');

    cout<<"\n";
    return 0;
}