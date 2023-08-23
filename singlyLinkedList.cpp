#include <iostream>
using namespace std;


 class node{
    public:
    int info;
    node *next;
    node(int data)
    {
        info = data;
        next = NULL;
    }
};
class SLL
{
    private:
    node *start;
public:
    SLL();
    void push_front(int);
    void push_back(int);
    void insert(int , int);
    void pop_front();
    void pop_back();
    void pop_between(int);
    node* search(int);
    void printList();
    ~SLL();
};

SLL::SLL()
{
    start = NULL;
}

SLL::~SLL()
{
    node *prev = NULL;
    while(start)
    {
        prev = start;
        start = start->next;
        delete prev;
    }
}
void SLL::push_front(int data)
{
    if(start == NULL)
    {
        start = new node(data);
        return;
    }

    node *s1 = new node(data);
    s1->next = start;
    start = s1;
}

void SLL::printList()
{
    node *temp = start;
    while(temp)
    {
        cout<<temp->info<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void SLL::push_back(int data)
{
    node *t = start;
    if(start == NULL){
        start = new node(data);
        return;
    }
    while(t->next != NULL)
       t = t->next;
    
    t->next = new node(data);
}

void SLL::insert(int data, int pos)
{
    node *t = start;
    int i = 1;

    if(start == NULL)
    {
        cout<<"Invalid position !"<<endl;
        return;
    }
    while(i < pos-1 && t->next != NULL)
    {
        t = t->next;
        i++;
    }

    if(pos < 2 || i < pos-1 && t->next == NULL)
    {
        cout<<"Invalid position !"<<endl;
        return;
    }

    node *newnode = new node(data);

    newnode->next = t->next;
    t->next = newnode;
}

void SLL::pop_front(){
     if(start == NULL)
     {
        cout<<"List is already empty "<<endl;
        return;
     }
     node *deletedNode = start;
     start = start->next;
     delete deletedNode;
}
node* SLL::search(int data)
{
    node *t = start;
    while(t){
        if(t->info == data)
            return t;
        t = t->next;
    }
    return NULL;
}
void SLL::pop_back()
{
    node *prev = nullptr , *curr = start;
    while(curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }
    delete prev->next;
    prev->next = nullptr; 
}

void SLL::pop_between(int pos){
    if(pos < 2 || start == NULL)
    {  
          cout<<"Invalid position \n";
	  return;
    }

   node *t = start,*delnode = NULL;
   int i = 1;

   while(i < pos-1 && t != NULL)
   {
       t = t->next;
       i++;
   }
   
   if(i < pos-1 && t == NULL){
        cout<<"Invalid position\n";
	return;
   }
  delnode = t->next;
  t->next = delnode->next;
  delete delnode; 
}
int main(void)
{
    SLL list;
    list.push_front(11);
    list.push_front(10);
    list.push_front(9);
    list.push_front(8);
    list.push_back(12);
    list.insert(12 ,2);
    list.insert(99,5);
    list.insert(77,6);

    list.printList();
   // list.pop_front();
    list.pop_back();
    list.pop_between(2);
    list.printList();
    return 0;
}
