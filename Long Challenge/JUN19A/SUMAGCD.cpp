#include<bits/stdc++.h>
using namespace std;
set < string > s;
void gen(string a,int n)
{
    if(n == 0)
    {
        s.insert(a);
    }
    else
    {
        gen(a+'0',n-1);
        gen(a+'1',n-1);
    }
}
int main()
{
    int T;  cin>>T;
    while(T--)
    {
        s.clear();
        int n,i;  cin>>n;
        int A[n];   
        for(i=0;i<n;i++)
            cin>>A[i];
        /*gen("",n);
        int ans = 0;
        string temp;
        for(set<string > :: iterator it = s.begin();it!=s.end();it++)
        {
            int gcd_b = -1;
            int gcd_c = -1;
            string s = *it;
            for(i = 0;i<s.size();i++)
            {
                if(s[i]=='0')
                {
                    if(gcd_b == -1) gcd_b = A[i];
                    gcd_b = __gcd(gcd_b,A[i]);
                }
                else
                {
                    if(gcd_c == -1) gcd_c = A[i];
                    gcd_c = __gcd(gcd_c,A[i]);
                }
            }
            if(gcd_b+gcd_c > ans )
            {
                ans = gcd_b + gcd_c;
                temp = s;
            }
            //ans = max(ans,gcd_b+gcd_c);
        }
        cout<<ans<<endl;
        cout<<temp<<endl;*/
        
        map < int,int > mp;
        for(i=0;i<n;i++)
            mp[A[i]]++;
        sort(A,A+n);
        int ans1 = A[n-1],temp=A[0];
        for(i=1;i<n-1;i++)
        {
            if(A[i]!=ans1)
                temp = __gcd(temp,A[i]);
        }
        ans1 = ans1+temp;
        i = n-2;
        while(i>=0 && A[i] == A[n-1])
        {
            i--;
        }
        int ans2 = 1;
        int p = i;
        if(p >= 0)
        {
            ans2 = A[i];temp = A[n-1];
            for(i=0;i<n-1;i++)
            {
                if(i != p && A[i]!= A[p])
                    temp = __gcd(temp,A[i]);
            }
            ans2 = ans2 + temp;
            //cout<<ans1<<" "<<ans2<<endl;
        }
        cout<<max(ans1,ans2)<<endl;
    }
}
        