//https://www.quora.com/How-do-I-find-the-max-value-of-an-array-after-several-updates
#include<bits/stdc++.h>
#define int long long int
using namespace std;
int t[131075<<2];
int I[131075<<2];
int A[131075];
set < pair < int,int > >s,p;
void build(int n,int m)
{
	int i;
	for(i=m;i<m+n;i++)	cin>>t[i],I[i]=i;
	for(i;i<m+m;i++)	t[i]=0,I[i]=i;
	for(i=m-1;i>0;i--)	
	{
		if(t[i<<1]>t[i<<1|1])
		{
			t[i]=t[i<<1];
			I[i]=I[i<<1];
		}
		else
		{
			t[i]=t[i<<1|1];
			I[i]=I[i<<1|1];
		}
	}
}
void update(int pos,int val,int m)
{
	int i;
	pos+=(m-1);
	t[pos]=val;
	for(i=pos/2;i>0;i/=2)	
	{
		if(t[i<<1]>t[i<<1|1])
		{
			t[i]=t[i<<1];
			I[i]=I[i<<1];
		}
		else
		{
			t[i]=t[i<<1|1];
			I[i]=I[i<<1|1];
		}
	}
	//for(i=0;i<2*m;i++)		cout<<t[i]<<"("<<I[i]<<") ";	cout<<endl;
}
void clear(int m)
{
	set < pair < int,int > > :: iterator st;
	while(s.size()>0)
	{
		st=s.begin();
		update(st->first-(m-1),st->second,m);
		s.erase(st);
	}
}
int max(int l,int r,int M) 
{
	int ans = -1,pos=-1;
	for(l=l+M-2,r=r+M;l^r^1;l>>=1,r>>=1) {
		if(~l&1) 
		{
			if(t[l^1]>ans)
			{
				ans = t[l^1];
				pos = I[l^1];
			}
		}
		if(r&1) 
		{
			if(t[r^1]>ans)
			{
				ans = t[r^1];
				pos = I[r^1];
			}
		}
	}
	return pos;
}
pair <int,int> pos_rwz(int l,int r,int m)
{
	int p=max(l,r,m);	
	pair < int,int > pv=make_pair(p,t[p]);
	s.insert(pv);
	update(p-(m-1),0,m);
	return pv;
}
main()
{
	int n,m,q,i;	cin>>n>>q;
	m=ceil(log2(n));
	m=pow(2,m);
	build(n,m);
	while(q--)
	{
		int ch;	cin>>ch;
		if(ch==2)
		{
			int l,r;	cin>>l>>r;
			pair < int,int > pa,pb,pc;
			pa=pos_rwz(l,r,m);	
			pb=pos_rwz(l,r,m);
			pc=pos_rwz(l,r,m);
			while(pa.second>=pb.second+pc.second && pc.second!=0)
			{
				//cout<<"values are"<<pa.second<<" "<<pb.second<<" "<<pc.second<<endl;
				pa=pb;
				pb=pc;
				pc=pos_rwz(l,r,m);
			}
			if(pc.second!=0)	cout<<pa.second+pb.second+pc.second<<endl;
			else				cout<<"0"<<endl;
			clear(m);
		}
		else
		{
			int pos,val;	cin>>pos>>val;
			update(pos,val,m);	
		}
		/*int l,r;	cin>>l>>r;
		cout<<query(l,r,m)<<endl;		*/
	}
}
