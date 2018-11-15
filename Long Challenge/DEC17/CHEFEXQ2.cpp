#include<bits/stdc++.h>
using namespace std;
//#define unordered_map map
#define unordered_set set
unordered_set < pair < int,int > > blocks;
unordered_set < pair < int,int > > :: iterator bt;
int A[100000];
int B[100000];
int mp[320][1000000];
int it;
void upd(int q,int n)
{
	for(bt=blocks.begin();bt!=blocks.end();bt++)
	{
		int pos=bt->first;
		int block=pos/q;
		int val=bt->second;
		int ini=0,i;
		for(i=block*q;i<pos;i++)	ini=ini^A[i];
		int p=ini;
		int p2=ini;
		p=p^A[i];
		p2=p2^val;
		A[i]=val;
		mp[block][p]--;
		mp[block][p2]++;
		for(i=pos+1;i<min(n,q*block+q);i++)
		{
			p=p^A[i];
			p2=p2^A[i];
			mp[block][p]--;
			mp[block][p2]++;
		}
		B[block]=p2;
	}
	blocks.clear();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q1,i,j,k;	cin>>n>>q1;
	for(i=0;i<n;i++)	cin>>A[i];
	int q=ceil(sqrt(n));
	for(i=0;i<q;i++)
	{
		int p=0;
		for(j=i*q;j<min(i*q+q,n);j++)
		{
			p=p^A[j];
			mp[i][p]++;
		}
		B[i]=p;
	}
	int last_update=n;
	while(q1--)
	{
		int type;	cin>>type;	
		if(type==1)
		{
			int pos,x;	cin>>pos>>x;
			blocks.insert(make_pair(pos-1,x));
			upd(q,n);
		}
		if(type==2)
		{
			int pos,k;	cin>>pos>>k;			
			pos--;
			int k2=0;
			int block=pos/q;
			int ans=0;
			for(i=0;i<block;i++)
			{
				ans+=mp[i][k^k2];
				k2=k2^B[i];
			}
			for(i=block*q;i<=pos;i++)
			{
				k2=k2^A[i];
				if(k==k2)	ans++;
			}
			cout<<ans<<"\n";
		}
	}
}
