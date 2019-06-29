#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define M 1000000007
vector < int > fac;
vector < int > ifac;
int powe(int a,int p)  //a^p
{
    if(p == 0)  return 1;
    if(p == 1)  return a;
    
    int temp = powe(a,p/2);
    temp = ((temp%M) * (temp%M))%M;
    if(p%2 == 1)
        temp = ((temp%M) * (a%M))%M;
    return temp;
}
void preprocess(int N)
{
    fac.resize(N+1);
    ifac.resize(N+1);
    int i;
    fac[0] = 1;
    for(i=1;i<=N;i++)
    {
        fac[i] = ((i%M)*(fac[i-1]%M))%M;
        ifac[i] = powe(fac[i],M-2);
    }
}
main()
{
    preprocess(300000);
    int n,q,i;    cin>>n>>q;
    int A[n];
    for(i=0;i<n;i++)
        cin>>A[i];
    int ans = 0;
    while(q--)
    {
        int l1,l2,r1,r2;
        cin>>l1>>l2>>r1>>r2;
        int l = (((l1%n)*(ans%n))%n + l2%n ) %n;
        int r = (((r1%n)*(ans%n))%n + r2%n ) %n; 
        if(l>r)
        {
            int t = l;
            l = r;
            r = t;
        }
        //cout<<l<<" "<<r<<endl;
        map < int ,int > mp;
        for(i=l;i<=r;i++)
        {
            mp[A[i]]++;
        }
        ans = fac[r-l+1];
        for(map<int,int > :: iterator mt= mp.begin();mt!=mp.end();mt++)
        {
            int temp =mt->second;
            ans = ((ans%M)*(ifac[temp]%M))%M;
        }
        cout<<ans<<endl;
    }
}
