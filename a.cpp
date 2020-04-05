#include<bits/stdc++.h>
int t;
using namespace std; 
void solvecase()
{
    int c,r,sum;
    int n,i,j,k;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    c=0;
    r=0;
    sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                sum+=arr[i][j];
            }
        }
    }
    i=0;
    again:
    while(i<n)
    {
        for(j=0;j<n;j++)
        {
            int e=arr[i][j];
            
            for(k=j+1;k<n;k++)
            {
                if(e==arr[i][k])
                {
                    r++;
                    i++;
                    goto again;
                }
            }
        }
        i++;
    }
    j=0; 
    c=0;
    again2:
    while(j<n)
    {
        for(i=0;i<n;i++)
        {
            int e=arr[i][j];
            for(k=i+1;k<n;k++)
            {
                if(e==arr[k][j])
                {
                    c++;
                    j++;
                    goto again2;
                }
            }
        }
        j++;
    }
    cout<<"Case #"<<t<<": "<<sum<<" "<<r<<" "<<c<<endl;
}

int main() 
{ 
    int tt;
    int a;
    cin>>tt;
    for(t=1;t<=tt;t++) 
    {
        solvecase();
    }
    return 0;
} 