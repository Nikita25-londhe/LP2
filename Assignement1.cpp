#include<iostream>
#include<queue>
using namespace std;
class Graph
{
    int v;
    int** graph;
    public:
    Graph()
    {
        cout<<"\nEnter no of vertices:";
        cin>>v;
        graph=new int*[v];
        for(int i=0;i<v;i++)
        {
            graph[i]=new int[v];
            for(int j=0;j<v;j++)
            {
                graph[i][j]=0;
            }
        }

    }
    void scanbyEdge()
    {
        int u,v;
        while(1)
        {
            cout<<"\nEnter u:";
            cin>>u;
            if(u==-1)
            {
                return;
            }
            cout<<"\nEnter v:";
            cin>>v;
            graph[u][v]=1;
            graph[v][u]=1;
        }
    }
    void printmatrix()
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void dfs()
    {
        int* visited=new int[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=0;
        }
        int start;
        cout<<"\nEnter start vertex:";
        cin>>start;
        dfs_rec(start,visited);
    }
    void dfs_rec(int start,int* visited)
    {
        cout<<"\n"<<start<<" is visited";
        visited[start]=1;
        for(int i=0;i<v;i++)
        {
            if(graph[start][i]!=0 && !visited[i])
            {
                dfs_rec(i,visited);
            }
        }
    }
    void bfs_helper(int* visited,queue<int>&q){
            if(q.empty())
                return;
    
            int src = q.front();
            q.pop();
    
            if(!visited[src]){
                cout << src << " ";
                visited[src] =1;
            }
    
            for(int i=0;i<v;i++){
                if(graph[src][i]!=0 && !visited[i]){
                    q.push(i);
                }
            }
            bfs_helper(visited, q);
        }
        void bfs_rec(int src){
           int* visited=new int[v];
           for(int i=0;i<v;i++)
           {
            visited[i]=0;
           }
            queue<int> q;
            q.push(src);
    
            bfs_helper(visited, q);
        }
};
int main()
{
    Graph g1;
    g1.scanbyEdge();
    g1.printmatrix();
    g1.dfs();
    int source;
    cout<<"\nEnter source:";
    cin>>source;
    g1.bfs_rec(source);
}
