#include<bits/stdc++.h>
using namespace std;
int isprime(int n)
{
	int i;
	for(i=2;i<n;i++)
		if(n%i==0)
			return 0;
	return 1;	
}
int main()
{
	int n,i;	cin>>n;
	int A[n+2];
	int omit=1;
	for(i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	set < pair < int,int > > edges,temp;
	set < int > taken;
	int last = 1;
	for(i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(isprime(A[i]+A[j]) && taken.find(j)==taken.end() && taken.find(i)==taken.end())
			{
				edges.insert(make_pair(i,j));
				taken.insert(i);
				taken.insert(j);
				last = j;
				break;
			}
		}
	}
	set < pair < int,int > > :: iterator it = edges.begin(),jt = edges.begin();
	it++;
	for(;it!=edges.end();it++)
	{
		temp.insert(make_pair(jt->first,it->first));			
		last = it->second;
	}
	for(int i = 1;i<=n;i++)
	{
		if(taken.find(i)==taken.end())
		{
			temp.insert(make_pair(last,i));
			last = i;
		}
	}
	for(it=edges.begin();it!=edges.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	for(it=temp.begin();it!=temp.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}
