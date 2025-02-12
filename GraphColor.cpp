#include<iostream>
using namespace std;
class Graph
{
    int n;
    int** graph;
    public:
    Graph(int a)
    {
        n=a;
        graph=new int*[n];
        for(int i=0;i<n;i++)
        {
            graph[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                graph[i][j]=0;
            }
        }
    }
    void readGraph()
    {
        cout<<"\nEnter graph matrix:";
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
        }
        cout<<endl;
    }
    bool canIColor(int v,int clr,int* color)
    {
        for(int i=0;i<n;i++)
        {
            if(graph[v][i]!=0 && color[i]==clr)
            {
                return false;
            }
        }
        return true;
    }
   void colorvertex(int v,int* color,int m)
   {
    if(v==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<color[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<m;i++)
    {
        if(canIColor(v,i,color))
        {
            color[v]=i;
            colorvertex(v+1,color,m);
        }
    }
    color[v]=-1;
   }
};
int main()
{
    int n;
    cout<<"\nEnter no of vertices:";
    cin>>n;
    Graph g1(n);
    g1.readGraph();
    g1.showGraph();
    int* color=new int[n];
    for(int i=0;i<n;i++)
    {
        color[i]=-1;
    }
    int m;
    cout<<"\nEnter no of avialable colors:";
    cin>>m;
    g1.colorvertex(0,color,m);
    return 0;
}
