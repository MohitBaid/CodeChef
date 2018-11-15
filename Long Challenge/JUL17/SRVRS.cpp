#include<bits/stdc++.h>
using namespace std;
struct cpu
{
	int x;
	int y;
	int t;
	int p;
	int i;
	int j;
}c[500000];
int m=0;
int compare(const void *a,const void *b)
{
	const struct cpu *A=(struct cpu*)a;
	const struct cpu *B=(struct cpu*)b;
	return A->p-B->p;
}
int main()
{
	int n,q,i,j;	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		int x,y,k;	cin>>x>>y>>k;
		for(j=0;j<k;j++)
		{
			c[m].x=x;
			c[m].y=y;
			c[m].t=0;
			c[m].i=i+1;
			c[m].j=j+1;
			cin>>c[m++].p;
		}
	}
	qsort(c,m,sizeof(cpu),compare);
	int t=0;
	/*for(i=0;i<m;i++)
	{
		cout<<c[i].i<<" "<<c[i].j<<" "<<c[i].p<<" "<<endl;
	}*/
	while(q--)
	{
		j=0;
		cout<<"?\n";
		int a,b;	cin>>a>>b;
		for(j=0;j<m;j++)
		{
			if(c[j].t<=t)	
			{	
				c[j].t=t+c[j].p;
				break;
			}
		}
		printf("! %d %d\n",c[j].i,c[j].j);
		t++;
	}
	cout<<"end\n";
}
