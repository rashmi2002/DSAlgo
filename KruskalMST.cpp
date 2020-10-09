#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
  public:
  int source;
  int dest;
  int weight;
};

bool compare(Edge E1, Edge E2)
{
  return E1.weight < E2.weight;
}

int findParent(int v, int *parent)
{
  if(parent[v]==v)
    return v;
  return findParent(parent[v], parent);
}

void kruskals(Edge *input, int V, int E)
{
  sort(input, input+E, compare);
  Edge *output=new Edge[V-1];
  int *parent=new int[V];

  for(int i=0;i<V;i++)
  {
    parent[i]=i;
  }

  int count=0;
  int i=0;
  while(count!=V-1)
  {
    Edge currentEdge=input[i];
    int sourceParent=findParent(currentEdge.source, parent);
    int destParent=findParent(currentEdge.dest, parent);
    if(sourceParent!=destParent)
    {
      output[count]=currentEdge;
      count++;
      parent[sourceParent]=destParent;

    }
    i++;
  }
  for(int i=0;i<V-1;i++)
  {
    if(output[i].source < output[i].dest)
      cout<<"  "<<output[i].source<<" -- "<<output[i].dest<<" -- "<<output[i].weight<<endl;
    else
      cout<<"  "<<output[i].dest<<" -- "<<output[i].source<<" -- "<<output[i].weight<<endl;
  }
}

int main()
{
  int V, E, tempX, tempY;
  cout<<"Enter the no. of vertices :"<<endl;
  cin >> V ;
  cout<<"Enter the no. of edges :"<<endl;
  cin>>E;
  Edge *input=new Edge[E];
  cout<<endl<<"       For each edge, we need source, destination and weight respectively ! "<<endl<<endl;
  for(int i=0;i<E;i++)
  {
    cout<<"For edge "<<i+1<<" , enter source, destination and weight respectively: "<<endl;
    int S,D,W;
    cin>>S>>D>>W;
    input[i].source=S;
    input[i].dest=D;
    input[i].weight=W;
  }
  cout<<" MST is: "<<endl;
  kruskals(input, V, E);
  return 0;
}

//We can check this algorithm for the following test case:

      /* Let us create following weighted graph
         5
     0--------1
     | \      |
    6|   \5   |15
     |      \ |
     2--------3
     4
      */
