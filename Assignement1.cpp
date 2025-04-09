// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;
class Graph
{
    int n;
    int** graph;
    public:
    Graph()
    {
        cout<<"\nEnter no of nodes:";
        cin>>n;
        graph=new int*[n];
        for(int i=0;i<n;i++)
        {
            graph[i]=new int[n];
        }
    }
    void readGraph()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
    }
     void showGraph()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void dfs()
    {
        int* visited=new int[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        int start;
        cout<<"\nEnter strating vertex:";
        cin>>start;
        cout<<"\nDFS Traversal";
        dfs_rec(visited,start);
    }
    void dfs_rec(int* visited,int v)
    {
        cout<<"\n"<<v<<" is visited";
        visited[v]=1;
        for(int i=0;i<n;i++)
        {
            if(graph[v][i]!=0 && visited[i]==0)
            {
                dfs_rec(visited,i);
            }
        }
    }
    void bfs()
    {
        int* visited=new int[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        int start;
        cout<<"\nEnter start vertex:";
        cin>>start;
        queue<int>q;
        q.push(start);
        cout<<"\nBFS Traversal:" ;
        bfs_rec(q,visited);
    }
    void bfs_rec(queue<int>&q,int* visited)
    {
        if(q.empty())
        {
            return;
        }
        int v=q.front();
        if(visited[v]==0)
        {
            cout<<"\n"<<v<<" is visted ";
            visited[v]=1;
            q.pop();
            for(int i=0;i<n;i++)
            {
                if(graph[v][i]!=0 && visited[i]==0)
                {
                    q.push(i);
                }
            }
            bfs_rec(q,visited);  
        }
    }
};
int main() 
{
    Graph g1;
    g1.readGraph();
    g1.showGraph();
    g1.dfs();
    g1.bfs();
    return 0;
}
