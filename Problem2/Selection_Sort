#include<iostream>
#include<algorithm>
using namespace std;
void print(int* arr,int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void scan(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
//Sorting in Descending order
void sort(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int max=arr[i];
        int ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>max)
            {
                max=arr[j];
                ind=j;
            }
        }
        swap(arr[i],arr[ind]);
    }
}
int main()
{
    int n;
    cout<<"\nEnter no of elements:";
    cin>>n;
    int* arr=new int[n];
    scan(arr,n);
    print(arr,n);
    sort(arr,n);
    print(arr,n);
    return 0;
}
