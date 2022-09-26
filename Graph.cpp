#include<iostream>
using namespace std;
struct Graph
{
    int Vertex;
    int Edge;
    int **Adj;
};
struct Graph* createAdjMatrixGraph(int Vertex,int Edge)
{
    int u,v;
    struct Graph *temp;
    temp=(struct Graph*)malloc(sizeof(struct Graph));
    temp->Vertex=Vertex;
    temp->Edge=Edge;
    temp->Adj=(int**)malloc(sizeof(int*)*temp->Vertex);
    for(int i=0;i<temp->Vertex;i++)
        temp->Adj[i]=(int*)malloc(sizeof(int)*temp->Vertex);
    for(int i=0;i<temp->Vertex;i++)
        for(int j=0;j<temp->Vertex;j++)
            temp->Adj[i][j]=0;
    for(int i=0;i<temp->Edge;i++){
        cin>>u>>v;
        temp->Adj[u][v]=1;
        temp->Adj[v][u]=1;
    }
    return temp;
}
int main()
{
    struct Graph *G;
    G=createAdjMatrixGraph(4,5);
    for(int i=0;i<G->Vertex;i++){
        for(int j=0;j<G->Vertex;j++)
            cout<<G->Adj[i][j]<<" ";
        cout<<endl;
    }
}
