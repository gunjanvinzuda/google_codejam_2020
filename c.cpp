#include<bits/stdc++.h>
int t;
using namespace std; 
void solvecase()
{
    int n;
    cin>>n;
    int s[n],e[n],o[n];
    int cs[n],ce[n],js[n],je[n];
    for(int i=0;i<n;i++)
    {
        cs[i]=-1;
        ce[i]=-1;
        js[i]=-1;
        je[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>e[i];
        o[i]=s[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i]>s[j])
            {
                int t=s[j];
                s[j]=s[i];
                s[i]=t;
                t=e[j];
                e[j]=e[i];
                e[i]=t;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    char a[n];
    cs[0]=s[0];
    ce[0]=e[0];
    string ans="";
    int ci=1,ji=0;
    bool check = true;
    for(int i=1;i<n;i++)
    {
        if(s[i]>=ce[ci-1])
        {
            cs[ci]=s[i];
            ce[ci]=e[i];
            ci++;
        }
        else if(ji==0||(s[i]>=je[ji-1]))
        {
            js[ji]=s[i];
            je[ji]=e[i];
            ji++;
        }
        else
        {
            check=false;
            break;
        }    
        
    }
    if(check)
    {
        int in=0;
        for(int i=0;((i<n)&&(cs[i]!=-1));i++)
        {
            s[i]=cs[i];
            e[i]=ce[i];
            a[i]='C';
            in=i+1;
        }
        for(int i=0;((i<n)&&(js[i]!=-1));i++,in++)
        {
            
            s[in]=js[i];
            e[in]=je[i];
            a[in]='J';
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[j]==o[i])
                {
                    int t=s[i];
                    s[i]=s[j];
                    s[j]=t;
                    t=e[i];
                    e[i]=e[j];
                    e[j]=t;
                    char r=a[i];
                    a[i]=a[j];
                    a[j]=r;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            ans+=a[i];
        }
    }
    else
    {
        ans="IMPOSSIBLE";
    }
    
    cout<<"Case #"<<t<<": "<<ans<<endl;
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