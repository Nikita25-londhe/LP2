#include<iostream>
#include<queue>
using namespace std;
#define N 3
/*
1 2 3
4 5 6
7 8 0

1 2 3
4 0 6
7 5 8
*/
class Node
{
    public:
    int matrix[N][N];
    int g,h;
    int x,y;
    Node* parent;
    Node(Node* parent,int matrix[N][N],int g,int x,int y,int nx,int ny)
    {
        this->parent=parent;
        this->g=g;
        this->x=x;
        this->y=y;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                this->matrix[i][j]=matrix[i][j];
            }
        }
        swap(this->matrix[nx][ny],this->matrix[x][y]);
        this->x=nx;
        this->y=ny;
    }
};
int heuristic(int start[][N],int goal[][N])
{
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(start[i][j] && start[i][j]!=goal[i][j])
            {
                count++;
            }
        }
    }
    return count;
}
void printMatrix(int matrix[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void showSteps(Node* temp)
{
    if(temp==NULL)
    {
        return;
    }
    showSteps(temp->parent);
    printMatrix(temp->matrix);
    cout<<"\ng="<<temp->g<<" h= "<<temp->h;
}
struct comp
{
    bool operator()(Node* lhs,Node* rhs)
    {
        return (lhs->g+lhs->h)>(rhs->g+rhs->h);
    }
};
void solve(int start[N][N],int goal[][N],int x,int y)
{
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    priority_queue<Node*,vector<Node*>,comp>pq;
    Node* root=new Node(NULL,start,0,x,y,x,y);
    pq.push(root);
    while(!pq.empty())
    {
        Node* temp=pq.top();
        pq.pop();
        temp->h=heuristic(temp->matrix,goal);
        if(temp->h==0)
        {
            showSteps(temp);
            return;
        }
        for(int i=0;i<4;i++)
        {
            int newx=dx[i]+temp->x;
            int newy=dy[i]+temp->y;
            if(newx>=0 && newx<N && newy>=0 && newy<N)
            {
                Node* child=new Node(temp,temp->matrix,temp->g+1,temp->x,temp->y,newx,newy);
                child->h=heuristic(child->matrix,goal);
                pq.push(child);
            }
        }
    }
}
int main()
{
    int start[N][N];
    int goal[N][N];
    cout<<"\nEnter start state:";
    int x,y;
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
    cout<<"\nEnter goal State:";
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
