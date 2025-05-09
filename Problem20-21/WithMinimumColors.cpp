#include<iostream>
#include<climits>
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
    int minColors;
    Graph(int n)
    {
        this->n=n;
        graph=new int*[n];
        for(int i=0;i<n;i++)
        {
            graph[i]=new int[n];
        }
        minColors=INT_MAX;
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
    void colorvertex(int v,int m,int* color,int usedColors)
    {
        if(v==n)
        {
            if(usedColors<minColors)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<color[i]<<" ";
                }
                cout<<endl;
                minColors=usedColors;
            }
            return;
        }
        if(usedColors>=minColors)
        {
            return;
        }
        for(int i=0;i<m;i++)
        {
            if(canIColor(v,i,color))
            {
                color[v]=i;
                int newusedColors=max(i+1,usedColors);
                colorvertex(v+1,m,color,newusedColors);
                color[v]=-1;
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
    g1.colorvertex(0,m,color,0);
    return 0;
}
