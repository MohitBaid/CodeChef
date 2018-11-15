#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		map < int , int > mp;
		set < pair < int ,int > > s;
		set < pair < int ,int > > :: iterator it,jt; 
		long long int sum=0,ans=-1;
		long long int A[n],B[n+1];
		B[0]=0;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
			B[i+1]=B[i]+A[i];
			B[i+1]%=n;
		}
		for(i=0;i<=n;i++)
		{
			s.insert(make_pair(B[i],i));
		}
		int p1,p2;
		for(it=s.begin();it!=s.end();it++)
		{
			jt=it;
			jt++;
			if(jt!=s.end())
			{
				if(it->first == jt->first)
				{
					p1=it->second;
					p2=jt->second;	
				}
			}
		}
		cout<<(p2-p1)<<endl;
		for(i=p1;i<p2;i++)
		{
			cout<<i+1<<" ";
		}
		cout<<endl;
	}
}
