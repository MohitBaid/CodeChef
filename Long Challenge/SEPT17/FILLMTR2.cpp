#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;		cin>>T;
	while(T--)
	{
		int n,q,i;	cin>>n>>q;
		bool flag=true;
		set < pair < pair<int,int>,int > > s;
		set < pair < pair<int,int>,int > > :: iterator it,jt;
		while(q--)
		{
			int i,j,val,temp;		
			cin>>i>>j>>val;
			if(i>j)
			{
				temp=i;
				i=j;
				j=temp;
			}
			if(i!=j)
			{
				it=s.find(make_pair(make_pair(i,j),val));
				jt=s.find(make_pair(make_pair(i,j),(val+1)%2));
				if(jt==s.end())
				{
					if(it==s.end())
						s.insert(make_pair(make_pair(i,j),val));
				}
				else					flag=false;
			}
			if(i==j && val==1)		flag=false;
		}
		for(it=s.begin();it!=s.end();it++)
			{
				int f1=it->first.first;
				int f2=it->first.second;
				cout<<f1<<" "<<f2<<" "<<it->second<<"\n";
			}
		int A[n+2];
		for(i=1;i<=n;i++)	A[i]=-1;
		if(flag)
		{
			for(it=s.begin();it!=s.end() && flag;it++)
			{
				int f1=it->first.first;
				int f2=it->first.second;
				if(it->second==0)
				{
					if(A[f1]==-1 && A[f2]==-1)
					{
						A[f1]=0;
						A[f2]=0;
					}
					else if(A[f1]!=-1 && A[f2]==-1)
					{
						A[f2]=A[f1];
					}
					else if(A[f1]==-1 && A[f2]!=-1)
					{
						A[f1]=A[f2];
					}
					else
					{
						if(A[f1]==A[f2]);
						else
						{
							flag=false;
							break;
						}
					}
				}
				else
				{
					if(A[f1]==-1 && A[f2]==-1)
					{
						A[f1]=0;
						A[f2]=1;
					}
					else if(A[f1]!=-1 && A[f2]==-1)
					{
						A[f2]=(A[f1]+1)%2;
					}
					else if(A[f1]==-1 && A[f2]!=-1)
					{
						A[f1]=(A[f2]+1)%2;
					}
					else
					{
						if(A[f1]!=A[f2]);
						else
						{
							flag=false;
							break;
						}
					}
				}
			}	
		}
		/*for(i=1;i<=n;i++)
			cout<<A[i]<<" ";
		cout<<endl;*/	
		if(flag)	cout<<"yes"<<endl;
		else		cout<<"no"<<endl;
	}
}
