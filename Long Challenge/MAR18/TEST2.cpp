#include<bits/stdc++.h>
#define MAX_SIZE 100005
using namespace std;
set < string > se[12];
int mp[1000][100002];
void gene(int p,string t)
{
	if(p==t.size())		se[p].insert(t);
	else
	{
		se[t.size()].insert(t);
		gene(p,t+'0');
		gene(p,t+'1');
	}
}
int factor(int prm[],int n)
{
	int c=0,i,j;
	if(n%2==0)
	{
		while(n%2==0)
			n=n/2;
		prm[c++]=2;	
	}
	for(i=3;i<=sqrt(n);i=i+2)
	{
		if(n%i==0)
		{
			while(n%i==0)
				n=n/i;
			prm[c++]=i;	
		}
	}
	if(n>1)		prm[c++]=n;
	return c;
}
int generate(int p,int A[],int B[],int C[])
{
	int bp=0,i;
	set <string > s=se[p];
	set < string > :: iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		string t=*it;
		int temp=1,c=0;
		for(i=0;i<t.size();i++)
			if(t[i]=='1')	
				temp*=A[i],c++;
		if(temp!=1)		
		{
			if(c%2==0)		C[bp]=1;
			else			C[bp]=-1;
			B[bp++]=temp;
		}
	}
	return bp;
}
void updateMP(int ch,int pos,int p,int A[])
{
	for(int i=0;i<p;i++)
	{
		if(ch==1)		mp[pos][A[i]]++;
		else			mp[pos][A[i]]--;
	}
}
main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	gene(11,"");
	int n,i,j,Q;	cin>>n;
	int prm[50],gen[513],cgen[513],A[n];
	int q=ceil(sqrt(n));
	for(i=0;i<n;i++)	cin>>A[i];
	for(i=0;i*q<n;i++)
	{
		for(j=i*q;j<min(n,i*q+q);j++)
		{
			int c=factor(prm,A[j]);
			c=generate(c,prm,gen,cgen);
			updateMP(1,i,c,gen);
		}
	}
	cin>>Q;
	while(Q--)
	{
		int ch;	cin>>ch;
		if(ch==1)
		{
			int pos,val;	cin>>pos>>val;
			pos--;
			int b=pos/q;
			int c=factor(prm,A[pos]);
			c=generate(c,prm,gen,cgen);
			updateMP(-1,b,c,gen);
			A[pos]=val;
			c=factor(prm,A[pos]);
			c=generate(c,prm,gen,cgen);
			updateMP(1,b,c,gen);
		}
		else
		{
			int l,r,g;	cin>>l>>r>>g;
			l--;r--;
			int c=factor(prm,g);
			int k=generate(c,prm,gen,cgen);
			int beg=l/q;
			int end=r/q;
			int ans=0;
			if(beg!=end)
			{
				for(i=l;i<(beg+1)*q;i++)		if(__gcd(A[i],g)>1)		ans++;
				for(i=beg+1;i<end;i++)
					for(j=0;j<k;j++)		
						ans-=(mp[i][gen[j]]*cgen[j]);		
				for(i=end*q;i<=r;i++)	if(__gcd(A[i],g)>1)		ans++;
			}
			else
			{	
				for(i=l;i<=r;i++)		
					if(__gcd(A[i],g)>1)		
						ans++;
			}
			cout<<(r-l+1-ans)<<endl;
		}
	}
} 
