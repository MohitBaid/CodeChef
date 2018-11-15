
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<list>
#include<utility>
#include<cstdio>
using namespace std;
struct planet
{
	long long int p;
	int no;
};
int cmpfunc(const void *p, const void *q) 
{
    int l = ((struct planet *)p)->p;
    int r = ((struct planet *)q)->p; 
    return (l - r);
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,j;	scanf("%d",&n);
		struct planet p[n];
		struct node* head[n]; 
		for(i=0;i<n;i++)
		{
			scanf("%lld",&p[i].p);
			p[i].no=i+1;
			head[i]=NULL;
		}	
		qsort(p,n,sizeof(struct planet),cmpfunc);
		vector< list<int> >AL(n+1);
		for(i=0;i<n-1;i++)
		{
			int s,e;
			scanf("%d %d",&s,&e);
			AL[s].push_back(e);
			AL[e].push_back(s);
		}
		for(i=1;i<=n;i++)
				AL[i].push_back(i);		
		for(i=1;i<=n;i++)
		{
			int f=n-1;
			list<int>::iterator itr =AL[i].begin();
			while(itr!=AL[i].end())
			{
				if(*itr==p[f].no)
				{
					itr =AL[i].begin();
					f--;
				}
				else
					++itr;			
			}
			printf("%d ",p[f].no);
		}	
	}
}
