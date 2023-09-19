#include <iostream>
using namespace std;

struct Pair{
    int vertex1;
    int vertex2;
};
class Graph{
    int v_count;
    int e_count;
    int **adj;
    public:
     Graph();
    ~Graph();
    void createGraph(Pair *,int , int);
    void printAdjacents(int);
    bool isIsolated(int);
    void printMatrix();
};

Graph::Graph()
{
    adj = NULL;
}
void Graph::createGraph(Pair *edges ,int v , int e)
{
    v_count = v;
    e_count = e;

    adj = new int*[v_count];

    for(int i = 0; i < v_count; ++i){
        adj[i] = new int[v_count];
    }

    for(int i = 0; i < v_count; ++i)
    {
        for(int j = 0; j < v_count; ++j)
             adj[i][j] = 0;
    }

     for (int i = 0; i < e_count; i++)
     {
          adj[edges[i].vertex1][edges[i].vertex2] = 1;
          adj[edges[i].vertex2][edges[i].vertex1] = 1;
     }
     
}

void Graph::printAdjacents(int node)
{
    if(node < v_count)
    {
        cout<<node<<"---> ";
        for(int i = 0; i < v_count; ++i)
        {
            if(adj[node][i])
               cout<<i<<" ";
        }
    }
}
bool Graph::isIsolated(int node)
{
    if(node < v_count)
    {
         for(int i = 0; i < v_count; ++i){
              if(adj[node][i])
                 return false;
         }
         return true;   
    }
        throw 1; 
}
void Graph::printMatrix()
{
    for(int i = 0; i < v_count; ++i)
    {
        for(int j = 0; j < v_count; ++j)
           cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}
Graph::~Graph()
{
    if(adj != NULL){
      for(int i = 0; i < v_count; ++i)
        delete [] adj[i];
      delete [] adj;
    }
}
int main()
{
    Graph g;
    int v , e;
    int node1 , node2;
    cout<<"Enter number of nodes : ";
    cin>>v;
    cout<<"Enter number of edges : ";
    cin>>e;

    Pair *edges = new Pair[e];
    for(int i = 0; i < e; ++i)
    {
        cin>>node1>>node2;
        edges[i].vertex1 = node1;
        edges[i].vertex2 = node2;
    }
    cout<<"\n"<<"Adjacency Matrix \n";
    g.createGraph(edges,v,e);
    g.printMatrix();

    cout<<"\n";
    //g.printAdjacents(0);
    try{
        g.isIsolated(1) ?  cout<<"true" : cout<<"false"; 
    }
    catch(int e)
    {
        cout<<"invalid node ! \n";
    }
    cout<<"\n";
    delete edges;
    return 0;
}