#include<iostream>
#include<queue>
using namespace std;
/*
0 3 1 0 0
3 0 7 7 0
1 7 0 1 4
0 7 1 0 4
0 0 4 3 0 */
class Graph
{
    int n;
    int** graph;
    public:
    Graph()
    {
        cout<<"\nEnter no of vertices:";
        cin>>n;
        graph=new int*[n];
        for(int i=0;i<n;i++)
        {
            graph[i]=new int[n];
        }
    }
    void readGraph()
    {
        cout<<"\nEnter input graph:";
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
    void BFS()
    {
        int* visited=new int[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        queue<int>q;
        int source;
        cout<<"\nEnter source:";
        cin>>source;
        visited[source]=1;
        q.push(source);
        bfs_rec(q,visited);
    }
    void bfs_rec(queue<int>&q,int* visited)
    {
        static int level=0;
        if(q.empty())
        {
            return;
        }
        int temp=q.size();
        cout<<"\n level "<<level<<" : ";
        for(int j=0;j<temp;j++)
        {
            int p=q.front();
            q.pop();
            cout<<p<<" ";
            for(int i=0;i<n;i++)
            {
                if(!visited[i] && graph[p][i])
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        level++;
        bfs_rec(q,visited);
    }
    void DFS()
    {
        int* visited=new int[n];
        int source;
        cout<<"\nEnter start vertex:";
        cin>>source;
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        dfs_rec(source,visited);
    }
    void dfs_rec(int v,int* visited)
    {
        cout<<"\n"<<v<<" is visited!";
        visited[v]=1;
        for(int i=0;i<n;i++)
        {
            if(graph[v][i] && !visited[i])
            {
                dfs_rec(i,visited);
            }
        }
    }
};
int main()
{
    Graph g1;
    g1.readGraph();
    g1.showGraph();
    cout<<"\nBFS traversal:";
    g1.BFS();
    cout<<"\nDFS traversal:";
    g1.DFS();
    return 0;
}
