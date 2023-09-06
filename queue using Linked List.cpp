#include <iostream>
using namespace std;

class node{
     public:
       int info;
       node *next;
       node(int info)
       {
          this->info = info;
           next = NULL;
       }
};

class queue
{
private:
    node *front;
    node *rear;
    int n;
public:
    queue();
    void enqueue(int);
    void dequeue();
    int size();
    node *getfront();
    node *getrear();
    ~queue();
};

queue::queue()
{
    front = rear = NULL;
    n = 0;
}

void queue::enqueue(int data)
{
    if(front == NULL)
    {
        front = new node(data);
        rear = front;
        n++;
    }
    else{
        rear->next = new node(data);
        rear = rear->next;
        n++;
    }

}

void queue::dequeue()
{
    if(front == NULL);
    else if(front == rear)
    {
        delete front;
        front = rear = NULL;
        n--;
    }
    else{
      node *temp = front;
      front = front->next;
      delete temp;
      n--;
    }
    
}
queue::~queue()
{
    node *temp;
    if(front)
    {
         while(front != rear)
         {
            temp = front;
            front = front->next;
            delete temp;
         }
         delete front;
    }
    cout<<"end\n";
}

int queue::size()
{
    return n;
}
node* queue::getfront()
{
    return front;
}

node* queue::getrear()
{
    return rear;
}
int main(void)
{
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    
    cout<<"front "<<q1.getfront()->info<<endl;
    cout<<"rear "<<q1.getrear()->info<<endl<<endl;
    cout<<"queue size "<<q1.size();
    q1.dequeue();
    cout<<"\nfront "<<q1.getfront()->info<<endl;
    cout<<"rear "<<q1.getrear()->info<<endl<<endl;
    cout<<"queue size "<<q1.size()<<endl;
    return 0;
}