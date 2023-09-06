#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
    node *prev;
    node(int info)
    {
        this->info = info;
        next = NULL;
        prev = NULL; 
    }
};

class deque{
    private:
     node *front;
     node *rear;
    public:
     deque();
     void pushAtfront(int);
     void pushAtrear(int);
     node* getfront();
     void PopFromRear();
     void PopFromFront();
     node* getrear();
     bool isEmpty();
     ~deque();

};
deque::deque()
{
    front = rear = NULL;
}

bool deque::isEmpty()
{
    return (front == NULL);
}
void deque::pushAtfront(int data)
{
    if(!isEmpty())
    {
        front->prev = new node(data);
        front->prev->next = front;
        front = front->prev;
    }
    else{
         front = new node(data);
         rear = front;
    }
}

deque::~deque()
{
    if(!isEmpty())
    {
         while(front != rear)
         {
            front = front->next;
            delete front->prev;
         }
         delete front;
    }
    cout<<"end\n";
}
void deque::pushAtrear(int data)
{
    if(!isEmpty())
    {
        rear->next = new node(data);
        rear->next->prev = rear;
        rear = rear->next;
    }
    else{
        front = new node(data);
        rear = front;
    }
}
void deque::PopFromFront()
{
    if(!isEmpty())
    {   
        if(front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else{
            front = front->next;
            delete front->prev;
            front->prev = NULL;
        }
    }
}

void deque::PopFromRear()
{
    if(!isEmpty())
    {
        if(front == rear)
        {
            delete rear;
            front = rear = NULL;
        }
        else{
             rear = rear->prev;
             delete rear->next;
             rear->next = NULL;
        }
    }
}
node* deque::getfront()
{
    return front;
}

node* deque::getrear()
{
    return rear;
}
int main()
{
    deque dec;
    dec.pushAtfront(12);
    dec.pushAtfront(100);
    dec.pushAtfront(77);
    dec.pushAtfront(12);
    dec.pushAtfront(99);
    dec.pushAtfront(88);
    dec.pushAtfront(67);

    cout<<"front "<<dec.getfront()->info<<endl;
    cout<<"rear "<<dec.getrear()->info<<endl;

    dec.PopFromRear();
    cout<<"front "<<dec.getfront()->info<<endl;
    cout<<"rear "<<dec.getrear()->info<<endl;

    dec.PopFromFront();

    cout<<"front "<<dec.getfront()->info<<endl;
    cout<<"rear "<<dec.getrear()->info<<endl;
    return 0;
}