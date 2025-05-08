#include<iostream>
#include<climits>
using namespace std;
#define INF 999
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
    int** cost;
    public:
    Graph()
    {
        cout<<"\nEnter no of vertices:";
        cin>>n;
        graph=new int*[n];
        cost=new int*[n];
        for(int i=0;i<n;i++)
        {
            graph[i]=new int[n];
            cost[i]=new int[n];
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
                if(graph[i][j]==0)
                {
                    cost[i][j]=INF;
                }
                else
                {
                    cost[i][j]=graph[i][j];
                }
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
    void Dijkstras()
    {
        int* visited=new int[n];
        int* from=new int[n];
        int* distance=new int[n];
        int source;
        cout<<"\nEnter source vertex:";
        cin>>source;
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
            from[i]=source;
            distance[i]=cost[source][i];
        }
        distance[source]=0;
        visited[source]=1;
        int ne=n-1;
        int v=source;
        int mincost=0;
        while(ne>0)
        {
            int mini=INF;
            for(int i=0;i<n;i++)
            {
                if(!visited[i] && distance[i]<mini)
                {
                    mini=distance[i];
                    v=i;
                }
            }
            visited[v]=1;
            for(int i=0;i<n;i++)
            {
                if(!visited[i] && distance[i]>(distance[v]+cost[v][i]))
                {
                    distance[i]=distance[v]+cost[v][i];
                    from[i]=v;
                }
            }
            ne--;
        }
        int temp=n-1;
        while(temp!=source)
        {
            cout<<"\n"<<temp<<" is visited";
            temp=from[temp];
        }
        cout<<"\n"<<temp<<" is visited";
        cout<<"\nMincost is "<<distance[n-1];
    }
};
int main()
{
    Graph g1;
    g1.readGraph();
    g1.showGraph();
    g1.Dijkstras();
    return 0;
}
