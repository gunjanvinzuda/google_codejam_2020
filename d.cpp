#include<bits/stdc++.h>
int t,b;
using namespace std; 
void solvecase()
{
    int bits[b];
    int comp[b],rev[b],comprev[b];
    for(int i=0;i<b;i++)
    {
         bits[i]=-1;
    }
    for(int q=0;q<150;q++)
    {
        if(q%10==1)
        {
            for(int k=0;k<b;k++)
            {
                if (bits[k]==0)
                {
                    comp[k]=1;
                }
                else
                {
                    comp[k]=0;
                }                
            }
            for(int i =b;i>=0;i--)
            {
                rev[b-i]=bits[i];
            }
            for(int i=0;i<b;i++)
            {
                if(comp[i]==0)
                {
                    comprev[i]=1;
                }
                else
                {
                    comprev[i]=0;
                }                
            }
        }
        else
        {
            int pos= 1 + (rand() % b);
            cin>>bits[pos];
        }
        
    }
    for(int i=0;i<b;i++)
    {
        cout<<bits[i];
    }
    char ch;
    cin>>ch;
    if (ch=='N')
    {
        exit(1);
    }
}

int main() 
{ 
    int tt;
    int a;
    cin>>tt>>b;
    for(t=1;t<=tt;t++) 
    {
        solvecase();
    }
    return 0;
} 