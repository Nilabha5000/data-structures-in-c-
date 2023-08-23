#include <iostream>
using namespace std;

struct node
{
      int info;
      node *next;
};


class CLL{
     node *Last;
	public:
        CLL();
    void push_back(int);
	void push_front(int);
	node *search(int);
	void push_after(int,int);
	void pop_front();
	void pop_back();
	void printCLL();
	~CLL();
};

CLL::CLL()
{
    Last = NULL;
}

CLL::~CLL()
{
      cout<<"dystructor called !\n";

      node *p;
      if(Last == NULL);
      else{
          p = Last->next;
          while(p != Last){
             Last->next = p->next;
             delete p;
             p = Last->next;
          }
      delete p;
   }
}
void CLL::push_back(int data)
{
    if(Last == NULL)
    {
        Last = new node;
	Last->info = data;
	Last->next = Last;
	return;
    }

    node *newnode = new node;
    newnode->info = data;
    newnode->next = Last->next;

    Last->next = newnode;

    Last = Last->next;
}
void CLL::printCLL()
{
	node *s;
	if(Last == NULL)
	  cout<<"List is empty \n";
	else
	{
	     s = Last->next;
	     while(s != Last)
             {
                  cout<<s->info<<" ";
		  s = s->next;
	     }
	      cout<<s->info<<" ";
        }
	 
}
void CLL::push_after(int dest , int data)
{
     node *n = search(dest);
     node *newnode;
     if(n == NULL){
	    cout<<"data not found ,so cannot push \n";
	    return;
     }

     newnode = new node;
     newnode->info = data;
    
     if(n == Last)
     {
          newnode->next = Last->next;
	  Last->next = newnode;
	  Last = newnode;
	  return;
     }

     newnode->next = n->next;
     n->next = newnode;

}
node* CLL::search(int data)
{
     
     if(Last != NULL){
       node*start = Last->next;
     while(start != Last){
            if(data == start->info)
		 return start;
	    start = start->next;
     }

     if(Last->info == data)
	     return Last;
     }
     return NULL;
}
void CLL::push_front(int data)
{
    node *newnode;

    newnode = new node;
    newnode->info = data;
    if(Last == NULL)
    {
         Last = newnode;
	 Last->next = Last;
	 return;
    }
    newnode->next = Last->next;
    Last->next = newnode;
}

void CLL::pop_front(){
    
	if(Last == NULL)
	{
	   cout<<"List is already empty \n";
	   return;
	}
	if(Last->next == Last)
	{
	    delete Last;
	    Last = NULL;
	    return;
	}
        
	node *p = Last->next;
	Last->next = p->next;
	delete p;
}

void CLL::pop_back(){
    node *s;

    if(Last == NULL)
    {
         cout<<"List is already empty !"<<endl;
	 return;
    }
    
    s = Last->next;
    if(s == Last)
    {
         delete Last;
         Last = NULL;
         return;
    }

    while(s->next != Last)
     s = s->next;

    s->next = Last->next;
    delete Last;
    Last = s;
}
int main()
{
   CLL list;
   
   list.push_back(1);
   list.push_back(2);
   list.push_back(3);
   list.push_back(4);
   list.push_back(5);
   list.push_after(5,44);
   list.push_front(10);
   list.push_after(2,67);
   list.printCLL();
   cout<<"\n";
   list.pop_front();
   list.pop_back();
   list.printCLL();
   cout<<"\n";
   return 0;
}
