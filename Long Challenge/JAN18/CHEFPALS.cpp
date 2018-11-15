#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;	cin>>n;
	int l[n],b[n],ans[n],d[n];
	for(i=0;i<n;i++)	cin>>l[i];
	for(i=0;i<n;i++)	cin>>b[i];
	for(i=0;i<n;i++)	d[i]=l[i]-b[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<d[i];j++)	cout<<"w";
		for(j=0;j<b[i];j++)	cout<<"b";
		cout<<endl;
	}
	set < pair < int,int  > >s;
	set < pair < int,int  > >:: iterator it;
	for(i=0;i<n;i++)
	{
		s.insert(make_pair(d[i],i+1));
	}
	i=0;
	for(it=s.begin();it!=s.end();it++)
	{
		//cout<<it->first<<" "<<it->second<<endl;
		ans[i++]=it->second;
	}
	//for(i=0;i<n;i++)	cout<<ans[i]<<" ";	cout<<endl;
	for(i=0;i<n;i=i+2)
	{
		cout<<ans[i]<<" ";
	}
	for(i=n-1;i>=0;i=i-2)
	{
		cout<<ans[i]<<" ";
	}
}
