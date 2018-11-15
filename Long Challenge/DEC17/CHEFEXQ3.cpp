#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct query
{
	int t;
	int pos;
	int k;
	int c;
};
int cmpfunc(const void *p,const void *q)
{
	struct query *x=(struct query *)p; 
	struct query *y=(struct query *)q;
	return x->pos - y->pos;
}
int main()
{
	int n,q,i,j;	cin>>n>>q;
	int A[n],ans[q],B[n];	query qu[q];
	for(i=0;i<n;i++)	cin>>A[i],B[i]=A[i];
	for(i=0;i<q;i++)
	{
		int t,pos,k;	
		cin>>t>>pos>>k;
		qu[i].t=t;
		qu[i].pos=pos-1;
		qu[i].k=k;
		qu[i].c=i;
		ans[i]=-1;
	}
	cout<<"as"<<endl;
	qsort(qu,q,sizeof(struct query),cmpfunc);
	cout<<"as"<<endl;
	for(i=0;i<q;i++)
	{
		cout<<qu[i].t<<" ";
		cout<<qu[i].pos<<" ";
		cout<<qu[i].k<<" ";
		cout<<qu[i].c<<" ";
		cout<<endl;
	}
	map < int, int > mp;
	int c=0;
	mp[A[0]]++;
	for(i=0;i<q;i++)
	{
		int pos=qu[i].pos;
		if(pos!=c)
		{
			for(j=c+1;j<=pos;j++)
			{
				A[j]^=A[j-1];
				mp[A[j]]++;
			}
			c=pos;
		}
		if(qu[i].t==1)
		{
			mp[A[pos]]--;
			A[pos]^=B[pos];
			B[pos]=qu[i].k;
			A[pos]^=B[pos];
				
		}
		else
		{
			ans[pos]=mp[qu[i].k];
		}
	}
	for(i=0;i<q;i++)
	{
		if(ans[i]!=-1)
		{
			cout<<ans[i]<<endl;
		}
	}
}
