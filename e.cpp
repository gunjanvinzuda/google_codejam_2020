#include <bits/stdc++.h>

using namespace std;

int arr[50][50], n, k, t;
int row[50][50]={0}, col[50][50]={0}; 
bool check=false;

void fun(int r, int c, int m) 
{
    if((r==n-1)&&(c==n)&&(m==k)&&!check)
    {
        check=true;
        cout<<"Case #"<<t<<": "<<"POSSIBLE\n";
        for(int i=0;i<n;i++) 
        {
            for (int j=0;j<n;j++) 
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    else if(r==n) 
    {
        return;
    }
    else if(c==n) 
    {
        fun(r+1,0,m);
    }
    for(int i=0;i<n&&!check;i++)
    {
        if(row[r][i]==0 && col[c][i]==0) 
        {
            row[r][i]=col[c][i]=1;
            if(r==c) 
            {
                m+=(i+1);
            }
            arr[r][c]=i+1;

            fun(r,c+1,m);

            row[r][i]=col[c][i]=0;
            if (r==c) 
            {
                m-=(i+1);
            }
            arr[r][c]=0;
        }
    }
}
void solvecase()
{
    scanf(" %d %d", &n, &k);
    fun(0, 0, 0);
    if (!check) {
        cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
    }
    check = false;
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