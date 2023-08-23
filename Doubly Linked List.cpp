#include <iostream>
using namespace std;

class node{
     public:
     int data;
     node *prev , *next;

     node(int data){
        this->data = data;
	prev = next = NULL;
     }
};


class DLL{
   node *start;
	public:
       DLL();
       void Push_front(int);
       void Push_back(int);
       void Push_between(int , int);
       void Pop_front();
       void Pop_back();
       void Pop_between(int);
       void PrintDoublyList();
       ~DLL();
};

DLL::DLL(){
    start = NULL;
}

DLL::~DLL(){
   cout<<"Dystructor called\n";
   if(start == NULL);
   else{
    while(start->next  != NULL){
	 if(start->prev != NULL){
	   delete start->prev;
	   start->prev = NULL;
	 }
	 start = start->next;
      }
      if(start->prev != NULL)
          delete start->prev;
      delete start;
     start = NULL;   
   }
}

void DLL::Push_front(int data){

      if(start == NULL)
      {
	    start = new node(data);
	    return;
      }

      node *Newnode = new node(data);

      Newnode->next = start;
      start->prev = Newnode;

      start = Newnode;
}

void DLL::Push_back(int data){

       if(start == NULL){
             start = new node(data);
	     return;
       }
       node *p = start;
       node *Newnode = new node(data);

       while(p->next != NULL)
	       p = p->next;

       p->next = Newnode;
       Newnode->prev = p;

}

void DLL::Push_between(int data , int pos)
{
       node *t = start;
       int i = 1;
       if(pos < 1 || t == NULL)
      {
	   cout<<"Invalid position\n";
	   return;
      }
       while(i < pos &&  t->next != NULL)
       {
            i++;
	    t=t->next;
       }

       if(i < pos && t->next == NULL)
       {
           cout<<"Invalid position\n";
	   return;
       }
       t = t->prev;
       node *Newnode = new node(data);
       Newnode->next = t->next;
       Newnode->prev = t;
       t->next = Newnode;
       Newnode->next->prev = Newnode;

}

void DLL::Pop_back(){
     if(start == NULL);

     else{
         node *t = start;

	 while(t->next != NULL)
	     t = t->next;

	   t = t->prev;

	   delete t->next;

	   t->next = NULL;
     }

}

void DLL::Pop_front()
{
    if(start == NULL);

    else{
	if(start->next != NULL){    
            start = start->next;
	    delete start->prev;
	    start->prev = NULL;
	}
	else
        {
	    delete start;
	    start = NULL;
	}
        
    }

}
void DLL::PrintDoublyList(){
    node *t = start;
    if(t == NULL)
    {
         cout<<"List is Empty nothing to print\n";
	 return;
    }
    while(t)
    {
         if(t->prev == NULL)
		 cout<<"NULL <----";
	  else
	     cout<<t->prev->data<<" <----";

	 cout<<t->data;

	 if(t->next == NULL)
	     cout<<"----> NULL \n";
	 else
	    cout<<"----> "<<t->next->data<<"\n";

	 t = t->next;
    }
}
int main(){

    DLL List;
    
    List.Push_back(1);
    List.Push_back(2);
    List.Push_back(3);
    List.Push_back(4);
    List.Push_back(5);
    List.Push_front(100);
    List.Push_front(200);
    List.Push_between(10,3);
    List.Push_between(77,8);    
    List.PrintDoublyList();
    cout<<"\n";
    return 0;
}
