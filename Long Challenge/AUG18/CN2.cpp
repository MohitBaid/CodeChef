#include<bits/stdc++.h>

using namespace std;
int main() {
    int n,x,i,j;    cin>>n>>x;
    int A[n];   
    map < int,int  > mp;
    for(i=0;i<n;i++)    cin>>A[i],mp[A[i]]++;
    int ans = 0;
    sort(A,A+n);
    for(i=0;i<n;i++)    cout<<A[i]<<" ";    cout<<endl;
    for(map < int,int  > :: iterator it = mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((A[i]*A[j]<=x) && (A[i]*A[j]!=0) && (x%(A[i]*A[j])==0))
            {
                //cout<<A[i]<<" "<<A[j]<<" "<<x/(A[i]*A[j])<<endl;
                map < int,int  > :: iterator it = mp.find(x/(A[i]*A[j]));
                if(it!=mp.end())
                    ans+=it->second;
                //cout<<ans<<endl;
            }
        }
        mp[A[i]]--;
        if(mp[A[i]]==0)
            mp.erase(A[i]);
    }
    cout<<ans<<endl;
    return 0;
}
