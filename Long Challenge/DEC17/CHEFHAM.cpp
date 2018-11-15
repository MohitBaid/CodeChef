#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		bool flag=true;
		int A[n],B[n];
		int P[100006][2];
		map < int ,int > mp;
		map < int ,int > :: iterator it;
		set < int > s1,s2;
		set < int > ::iterator jt,kt;
		for(i=0;i<=100005;i++)
		{
			P[i][0]=-1;
			P[i][1]=-1;
		}
		for(i=0;i<n;i++)	cin>>A[i];
		for(i=0;i<n;i++)
		{
			mp[A[i]]++;
			if(P[A[i]][0]==-1)	P[A[i]][0]=i;
			else				P[A[i]][1]=i;
		}
		for(it=mp.begin();it!=mp.end();it++)
		{
			if(it->second==1)	s1.insert(it->first);
			else				s2.insert(it->first);
		}
		if(s1.size()%2==1 && s2.size()%2==1 && flag)
		{
			flag=false;
			if(s2.size()==1 && s1.size()==1)
			{
				jt=s2.begin();
				int e=*jt;
				s2.erase(e);
				kt=s1.begin();
				int o1=*kt;
				s1.erase(o1);
				B[P[e][0]]=o1;
				B[P[e][1]]=e;
				B[P[o1][0]]=e;
			}
			else if(s1.size()>1)
			{
				jt=s2.begin();
				int e=*jt;
				s2.erase(e);
				kt=s1.begin();
				int o1=*kt;
				s1.erase(o1);
				kt=s1.begin();
				int o2=*kt;
				s1.erase(o2);
				kt=s1.begin();
				int o3=*kt;
				s1.erase(o3);
				B[P[e][0]]=o1;
				B[P[e][1]]=o2;
				B[P[o1][0]]=e;
				B[P[o2][0]]=o3;
				B[P[o3][0]]=e;
			}
			else
			{
				jt=s1.begin();
				int e=*jt;
				s1.erase(e);
				kt=s2.begin();
				int o1=*kt;
				s2.erase(o1);
				kt=s2.begin();
				int o2=*kt;
				s2.erase(o2);
				kt=s2.begin();
				int o3=*kt;
				s2.erase(o3);
				B[P[e][0]]=o1;
				B[P[o1][0]]=o2;
				B[P[o2][0]]=o3;
				B[P[o3][0]]=o1;
				B[P[o1][1]]=o2;
				B[P[o2][1]]=o3;
				B[P[o3][1]]=e;
			}
		}
		if(flag)
		{
			if(s1.size()%2==1 && s2.size()%2==0 && s2.size()>0)
			{
				flag=false;
				jt=s2.begin();
				int e1=*jt;
				s2.erase(e1);
				kt=s2.begin();
				int e2=*kt;
				s2.erase(e2);
				kt=s1.begin();
				int o=*kt;
				s1.erase(o);
				B[P[e1][0]]=e2;
				B[P[e1][1]]=e2;
				B[P[e2][0]]=e1;
				B[P[e2][1]]=o;
				B[P[o][0]]=e1;
			}
			else if(s2.size()==0 && s1.size()%2==1)
			{
				flag=false;
				if(s1.size()>1)
				{
					kt=s1.begin();
					int o1=*kt;
					s1.erase(o1);
					kt=s1.begin();
					int o2=*kt;
					s1.erase(o2);
					kt=s1.begin();
					int o3=*kt;
					s1.erase(o3);
					B[P[o1][0]]=o2;
					B[P[o2][0]]=o3;
					B[P[o3][0]]=o1;
				}
				else
				{
					kt=s1.begin();
					int o1=*kt;
					s1.erase(o1);
					B[P[o1][0]]=o1;
				}
			}
		}
		if(flag)
		{
			if(s1.size()%2==0 && s2.size()%2==1 &&s1.size()>0)
			{
				flag=false;
				jt=s2.begin();
				int e=*jt;
				s2.erase(e);
				kt=s1.begin();
				int o1=*kt;
				s1.erase(o1);
				kt=s1.begin();
				int o2=*kt;
				s1.erase(o2);
				B[P[e][0]]=o1;
				B[P[e][1]]=o2;
				B[P[o1][0]]=e;
				B[P[o2][0]]=e;
			}
			else if(s1.size()==0 && s2.size()%2==1)
			{
				flag=false;
				if(s2.size()>1)
				{
					kt=s2.begin();
					int o1=*kt;
					s2.erase(o1);
					kt=s2.begin();
					int o2=*kt;
					s2.erase(o2);
					kt=s2.begin();
					int o3=*kt;
					B[P[o1][0]]=o2;
					B[P[o2][0]]=o3;
					B[P[o3][0]]=o1;
					B[P[o1][1]]=o2;
					B[P[o2][1]]=o3;
					B[P[o3][1]]=o1;
				}
				else
				{
					kt=s2.begin();
					int o1=*kt;
					s2.erase(o1);
					B[P[o1][0]]=o1;
					B[P[o1][1]]=o1;
				}
			}
		}
		if(s1.size()%2==0 && s1.size()>0)
		{
			while(s1.size()>0)
			{
				kt=s1.begin();
				int o1=*kt;
				s1.erase(o1);
				kt=s1.begin();
				int o2=*kt;
				s1.erase(o2);
				B[P[o1][0]]=o2;
				B[P[o2][0]]=o1;
			}
		}
		if(s2.size()>0 && s2.size()%2==0)
		{
			while(s2.size()>0)
			{
				kt=s2.begin();
				int o1=*kt;
				s2.erase(o1);
				kt=s2.begin();
				int o2=*kt;
				s2.erase(o2);
				B[P[o1][0]]=o2;
				B[P[o2][0]]=o1;
				B[P[o1][1]]=o2;
				B[P[o2][1]]=o1;
			}
		}
		int ham=0;
		for(i=0;i<n;i++)
		{
			if(A[i]!=B[i])	ham++;
		}
		cout<<ham<<endl;
		for(i=0;i<n;i++)
			cout<<B[i]<<" ";
		cout<<endl;	
	}
}
