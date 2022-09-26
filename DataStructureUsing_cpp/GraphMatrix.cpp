#include<iostream>
#include<queue>
#include<conio.h>
using namespace std;
struct Graph
{
    int V;
    int E;
    int **adj;
};
void DFS(Graph *g,int s,bool b[])
{

}
void BFS(Graph *g,int s)
{
    queue<int> q;
    bool b[g->V] = {0};

        q.push(s);
        b[s] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            cout<<x<<" ";
            for(int i=0;i<g->V;i++)
                if(g->adj[x][i]==1)
                    if(b[i]==0){
                        q.push(i);
                        b[i]=1;
                    }
        }
}
Graph* createGraph(int v,int e)
{
    Graph *temp = new Graph;
    temp->V = v;
    temp->E = e;
    temp->adj = new int*[v];
    for(int i=0; i < v; i++)
        temp->adj[i] = new int[v];

    for(int i=0; i < v;i++)
        for(int j=0; j < v;j++)
            temp->adj[i][j]=0;
    return temp;
}
Graph* insertEdgesInGraph(int v,int e)
{
    int a,b;
    Graph *g = createGraph(v,e);
    for(int i=0;i<e;i++){
            //cout<<"Enter the "<<i+1<<" Edge";
            cin>>a>>b;
            g->adj[a][b] = 1;
            g->adj[b][a] = 1;
    }
    return g;
}
void printGraph(Graph *p)
{
    for(int i=0; i < p->V;i++){
        for(int j=0; j < p->V;j++){
            cout<<p->adj[i][j]<<" ";
        }
    cout<<endl;
    }
}
int main()
{
    Graph *g;
    int N,M;
    cout<<"ENTER NUMBER OF VERTEX\n";
    cin>>N;
    cout<<"ENTER NUMBER OF EDGE\n";
    cin>>M;
    g = insertEdgesInGraph(N,M);
    printGraph(g);
    cout<<endl;
    getch();
    BFS(g,2);
}
/* // Edge input    v=7,e=9
0 1
0 2
0 3
1 4
2 4
2 5
3 5
4 6
5 6*/
