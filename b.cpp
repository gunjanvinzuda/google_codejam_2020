#include<bits/stdc++.h>
#include<iostream> 
#include<string>
#include<typeinfo>
int t;
using namespace std; 
void solvecase()
{
    string s,os="";
    cin>>s;
    int n=atoi(s.c_str());    
    if(n==0)
        cout<<"Case #"<<t<<": "<<s<<endl;
    else
    {
        os=s[0];
        for(int j=0;j<((int)s[0]-48);j++)
        {
            os="("+os+")";
        }
        for(int j=1;j<s.length();j++)
        {
            string start,end;
            int num=(int)s[j]-48,pos;
            if(num!=0)
            {
                pos=os.length()-num;
            }
            else
            {
                os+=s[j];
                continue;
            }
            if(pos<0)
            {
                string temp;
                temp=s[j];
                for(int k=0;k<((int)s[j]-48);k++)
                {
                    temp="("+temp+")";
                }   
                os+=temp;
            }
            else
            {
                if(os[pos]==')')
                {
                    start=os.substr(0,pos);
                    end=os.substr(pos,os.length());
                    os=start+s[j]+end;
                }
                else
                {
                    start=os.substr(0,pos+1);
                    end=os.substr(pos+1,os.length());
                    os=start+"("+s[j]+")"+end;
                }
            }
            
        }
        cout<<"Case #"<<t<<": "<<os<<endl;
    }    
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