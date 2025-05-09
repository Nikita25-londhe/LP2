#include<iostream>
using namespace std;
/*
0 3 1 0 0
3 0 7 7 0
1 7 0 1 4
0 7 1 0 4
0 0 4 3 0
 */
class Graph
{
    public:
    int n;
    int** graph;
    Graph(int n)
    {
        this->n=n;
        graph=new int*[n];
        for(int i=0;i<n;i++)
        {
            graph[i]=new int[n];
        }
    }
    void readGraph()
    {
        cout<<"\nEnter graph input:";
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
        cout<<"\nGraph:";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    bool canIColor(int v,int clr,int* color)
    {
        for(int i=0;i<n;i++)
        {
            if(graph[v][i] && color[i]==clr)
            {
                return false;
            }
        }
        return true;
    }
    void colorvertex(int v,int m,int* color)
    {
        if(v==n)
        {
            for(int i=0;i<n;i++)
            {
                cout<<color[i]<<" ";
            }
            cout<<endl;
            color[v]=-1;
            return;
        }
        for(int i=0;i<m;i++)
        {
            if(canIColor(v,i,color))
            {
                color[v]=i;
                colorvertex(v+1,m,color);
            }
        }

    }

};
int main()
{
    cout<<"\nEnter no o vertices:";
    int n;
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
    cout<<"\nEnter no of available colors:";
    cin>>m;
    g1.colorvertex(0,m,color);
    return 0;
}
