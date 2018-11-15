#include<bits/stdc++.h>
using namespace std;
set < pair < int, string > > s;
set < pair < int, string > > ::iterator it;
void generate(string g,int sal,int S[],int i,int n)
{
	if(g.size()==n)
	{
		s.insert(make_pair(sal,g));
	}
	else
	{
		generate(g+'0',sal,S,i+1,n);
		generate(g+'1',sal+S[i],S,i+1,n);
	}
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int k,i;	cin>>k;
		int P[k],S[k];
		for(i=0;i<k;i++)		cin>>P[i]>>S[i];
		generate("",0,S,0,k);
		int n;	cin>>n;
		int ans=-1;
		int D[n],M[n];
		for(i=0;i<n;i++)		cin>>D[i]>>M[i];
		if(n==1)
		{
			for(it=s.begin();it!=s.end();it++)
			{
				int cap=0;
				string g=it->second;
				for(i=0;i<g.size();i++)
				{
					if(g[i]=='1')
						cap+=P[i];
				}
				if(cap*M[0]>=D[0])
				{
					ans=it->first;
					break;
				}
			}	
		}
		else
		{
			int j;
			double temp[n];
			for(i=0;i<n;i++)
			{
				temp[i]=D[i]*1.0/M[i];
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<n-1-i;j++)
				{
					if(temp[j]>temp[j+1])
					{
						double k=M[j];
						M[j]=M[j+1];
						M[j+1]=k;
					}
				}
			}
			for(it=s.begin();it!=s.end();it++)
			{
				string g=it->second;
				int cap=0,fu=0;
				int flag=0;
				for(i=0;i<g.size();i++)
				{
					if(g[i]=='1')
						cap=P[i],fu++;
				}
				int l=0,r=n-1;
				while(l<=r)
				{
					double s=0.0;
					s=temp[r];
					r--;
					if(s>cap)
					{
						flag=1;
						break;
					}
					else
					{
						while(s+temp[l]<=cap && l<=r)
						{
							s=s+temp[l];
							l++;
						}
						fu--;
						s=0;
					}
					if(fu<0)
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					ans=it->first;
					break;
				}
			}
		}
		cout<<ans<<endl;
		s.clear();
	}
}
