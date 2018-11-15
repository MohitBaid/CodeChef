#include<bits/stdc++.h>
using namespace std;
//#define unordered_map map
set < pair < int ,int >  >blocks;
set < pair < int ,int >  > :: iterator bt;
int A[100000];
int B[1000];
int B2[1000][1000];
unordered_map < int,int > mp[1000],mp2[1000][100];
unordered_map < int,int > :: iterator it;
void upd(int q,int w,int n)
{
	for(bt=blocks.begin();bt!=blocks.end();bt++)
	{
		int block=bt->first;
		int sblock=bt->second;
		//cout<<"Updating :"<<block<<" "<<sblock<<endl;
		int p=0,i;
		for(i=0;i<sblock;i++)
		{
			p=p^B2[block][i];
		}
		for(it=mp2[block][sblock].begin();it!=mp2[block][sblock].end();it++)
		{
			mp[block][it->first^p]-=mp2[block][sblock][it->first];
		}
		mp2[block][sblock].clear();
		int p2=0;
		for(int i=q*block+w*sblock;i<min(min(q*block+w*sblock+w,block*q+q),n);i++)
		{
			p2=p2^A[i];
			p=p^A[i];
			mp[block][p]++;
			mp2[block][sblock][p2]++;
		}
		B[block]^=p2;
		B[block]^=B2[block][sblock];
		B2[block][sblock]=p2;
	}
	blocks.clear();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q1,i,j,k,i2;	cin>>n>>q1;
	for(i=0;i<n;i++)	cin>>A[i];
	int q=ceil(sqrt(n));
	int w=ceil(sqrt(q));
	for(i=0;i<q;i++)
	{
		int p=0;
		for(j=0;j<w;j++)
		{
			int p2=0;
			for(i2=i*q+j*w;i2<min(n,min(i*q+q,i*q+j*w+w));i2++)
			{
				//cout<<A[i2]<<"("<<i2<<") ";
				p2=p2^A[i2];
				p=p^A[i2];
				mp2[i][j][p2]++;
				mp[i][p]++;
			}
			B2[i][j]=p2;
			//cout<<endl;
		}
		B[i]=p;
		//cout<<endl;
	}
	int last_update=n;
	while(q1--)
	{
		int type;	cin>>type;	
		if(type==1)
		{
			int pos,x;	cin>>pos>>x;
			A[pos-1]=x;
			blocks.insert(make_pair((pos-1)/q,((pos-1)%q)/w));
			if(pos-1<last_update)	last_update=pos-1;
		}
		if(type==2)
		{
			int pos,k;	cin>>pos>>k;			
			pos--;
			if(pos>last_update)		
			{
				upd(q,w,n);
				last_update=n;
			}
			int k2=0;
			int block=pos/q;
			int sblock=block/w;
			int ans=0;
			for(i=0;i<block;i++)
			{
				ans+=mp[i][k^k2];
				k2=k2^B[i];
			}
			//cout<<ans<<endl;
			for(i=0;i<sblock;i++)
			{
				ans+=mp2[block][i][k^k2];
				k2=k2^B2[block][i];
			}
			//cout<<ans<<endl;
			for(i=block*q+sblock*w;i<=pos;i++)
			{
				k2=k2^A[i];
				if(k==k2)
					ans++;
			}
			cout<<ans<<"\n";
		}
	}
}
