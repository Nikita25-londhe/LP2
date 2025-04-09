// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int findmin(int i,int n,int* nums)
{
    int mini=nums[i];
    int minInd=i;
    for(int j=i;j<n;j++)
    {
        if(nums[j]<mini)
        {
            mini=nums[j];
            minInd=j;
        }
    }
    return minInd;
}
void selection(int* nums,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int ind=findmin(i+1,n,nums);
        if(nums[ind]<nums[i])
        {
            swap(nums[ind],nums[i]);
        }
    }
}
int main() 
{
    int n;
    cout<<"\nEnter no of elements:";
    cin>>n;5
    int* nums=new int[n];
    cout<<"\nEnter elemnets of array:";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    selection(nums,n);
    cout<<"\nAfter sorting:";
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
