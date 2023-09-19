#include <iostream>

using namespace std;
struct node{
    int vertex;
    node *next;
};
class Graph{
     node **adj;
     int v_count;
     node* push_back(node *,int);
     public:
     Graph();
     ~Graph();
     void CreateGraph(int);
     void addEdge(int, int);
     void printGraph();

};

Graph::Graph(){
    adj = NULL;
}
Graph::~Graph()
{
    if(adj != NULL)
    {
        node *prev;
        for(int i = 0; i < v_count; ++i)
        {
            while(adj[i])
            {
                prev = adj[i];
                adj[i] = adj[i]->next;
                delete prev;
            }
        }
        delete[] adj;
    }
}
node* Graph::push_back(node *head , int data)
{
    if(head == NULL)
    {
        head = new node;
        head->vertex = data;
        head->next = NULL;
        return head;
    }
    else{
        node *t = head;
        node *newnode = new node;
        newnode->vertex = data;
        newnode->next = NULL;
        while (t->next)
          t = t->next;
        t->next = newnode;
    }
    return head;
}
void Graph::CreateGraph(int V)
{
    v_count = V;
    adj = new node*[v_count];

    for(int i = 0; i < v_count; ++i)
       adj[i] = NULL;
}

void Graph::addEdge(int u,int v)
{
    adj[u] = push_back(adj[u],v);
    adj[v] = push_back(adj[v],u);
}

void Graph::printGraph()
{
    node* t = NULL;
    for(int i = 0; i < v_count; ++i)
    {
        cout<<i<<" ---> ";
        t = adj[i];
        while(t)
        {
            cout<<t->vertex<<" ";
            t = t->next;
        }
        cout<<"NULL\n";
    }
}
int main()
{
    Graph g;
    g.CreateGraph(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printGraph();
    return 0;
}