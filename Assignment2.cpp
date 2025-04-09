#include<iostream>
#include<queue>
#include<climits>
using namespace std;
#define N 3
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
/*
 1 2 3
 0 4 6
 7 5 8
 1 2 3 
 4 5 6 
 7 8 0
*/
class Node
{
    public:
    int mat[N][N];
    int x,y,nx,ny,g,h;
    Node* parent;
    Node(Node* parent,int matrix[N][N],int x,int y,int nx,int ny,int g)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
               this->mat[i][j]=matrix[i][j];
            }
        }
        h=INT_MAX;
        this->g=g;
        swap(mat[x][y],mat[nx][ny]);
        this->x=nx;
        this->y=ny;
        this->parent=parent;
    }
};
int heuristic(int mat[N][N],int goal[N][N])
{
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j] && mat[i][j]!=goal[i][j])
            {
                count++;
            }
        }
    }
    return count;
}
struct comp
{
    bool operator()(Node* lhs,Node* rhs)const
    {
        return (lhs->g+lhs->h)>(rhs->g+rhs->h);
    }
};
void printMatrix(int mat[N][N],int g,int h)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\ng="<<g<<"\nh="<<h<<"\nf="<<(g+h);
}
void printPath(Node* T)
{
    if(T==NULL)
    {
        return ;
    }
    printPath(T->parent);
    printMatrix(T->mat,T->g,T->h);
}
void solve(int start[N][N],int goal[N][N],int x,int y)
{
    Node* root=new Node(NULL,start,x,y,x,y,0);
    root->h=heuristic(root->mat,goal);
    priority_queue<Node*,vector<Node*>,comp>pq;
    pq.push(root);
    while(!pq.empty())
    {
        Node* T=pq.top();
        if(T->h==0)
        {
            printPath(T);
            return;
        }
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int nx=T->x+dx[i];
            int ny=T->y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N)
            {
                Node* child=new Node(T,T->mat,T->x,T->y,nx,ny,T->g+1);
                child->h=heuristic(child->mat,goal);
                pq.push(child);   
            }
        }
    }
}
int main()
{
    int start[N][N];
    int goal[N][N];
    int x=-1,y=-1;
    cout<<"\nEnter start state:";
    for(int i=0;i<N;i++)
    {
       for(int j=0;j<N;j++)
       {
            cin>>start[i][j];
            if(start[i][j]==0)
            {
                x=i;
                y=j;
            }
       }
    }
    cout<<"\nEnter goal state:";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>goal[i][j];
        }
    }
    solve(start,goal,x,y);
    return 0;
}
