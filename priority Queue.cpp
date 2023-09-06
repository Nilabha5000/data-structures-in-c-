#include <iostream>

struct node{
     int info;
     int priorityNumber;
     node *next;
};

class priorityQueue
{
private:
      node *start;
public:
    priorityQueue();
    bool IsEmpty();
    void push(int , int);
    int getHighestPriorityNumber();
    int getHighestPriorityElement();
    void pop();
    ~priorityQueue();
};

priorityQueue::priorityQueue()
{
    start = NULL;
}

bool priorityQueue::IsEmpty()
{
    return (start == NULL);
}
void priorityQueue::push(int data , int pn)
{
    node *newnode = new node;
    newnode->info = data;
    newnode->priorityNumber = pn;
    newnode->next = NULL;
    
    if(IsEmpty())
        start = newnode;
    else if(newnode->priorityNumber > start->priorityNumber)
    {
        newnode->next = start;
        start = newnode;
    }
    else{
        node *prev = NULL;
        node *t = start;
        while(t != NULL && newnode->priorityNumber <= t->priorityNumber)
        {
            prev = t;
            t = t->next; 
        }
        if(t != NULL)
            newnode->next = prev->next;
        prev->next = newnode;
    }
}
priorityQueue::~priorityQueue()
{
       node *prev = NULL;
       while(start)
       {
           prev = start;
           start = start->next;
           delete prev;
       }
}

int priorityQueue::getHighestPriorityNumber()
{
    if(start == NULL)
        throw 1;
    return start->priorityNumber;
}


int priorityQueue::getHighestPriorityElement()
{
    if(start == NULL)
       throw 1;
    return start->info;
}
void priorityQueue::pop()
{
    if(start)
    {
        node *prev = start;
        start = start->next;
        delete prev;
    }
}
int main(void)
{
    priorityQueue p;
    p.push(1,10);
    p.push(100,5);
    p.push(9,50);
    p.push(2,10);
    p.push(4,20);

    while(!p.IsEmpty()){
        std::cout<<p.getHighestPriorityElement()<<" : "<<p.getHighestPriorityNumber()<<std::endl;
        p.pop();
    }
    return 0;
}